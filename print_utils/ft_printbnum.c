/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:12:32 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 15:34:53 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int print_number_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nbrl;
	int				total;

	total = 0;
	nbrl = nbr;
	base_len = ft_strlen(base);
	if (nbrl >= base_len)
	{
		total += print_number_base(nbrl / base_len, base);
		total += print_number_base(nbrl % base_len, base);
	}
	else
	{
		total += print_char(base[nbrl]);
	}
	return (total);
}

int	ft_printbnum(int nbr, int is_maj, t_opt opt)
{
	int	total;

	total = 0;
	if (opt.sharp && nbr != 0)
	{
		if (is_maj)
			total += print_str("0X");
		else
			total += print_str("0x");
	}
	if (is_maj)
		total += print_number_base(nbr, "0123456789ABCDEF");
	else
		total += print_number_base(nbr, "0123456789abcdef");
	return (total);
}
