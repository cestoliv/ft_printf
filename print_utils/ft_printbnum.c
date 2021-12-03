/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:12:32 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/03 11:33:53 by ocartier         ###   ########lyon.fr   */
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

static int  get_hex_size(int nbr)
{
    int    			 total;
	unsigned int	nbrl;

    total = 0;
	nbrl = nbr;
    if (nbrl >= 16)
    {
        total += get_hex_size(nbrl / 16);
        total += get_hex_size(nbrl % 16);
    }
    else
        total++;
    return (total);
}


int	ft_printbnum(int nbr, int is_maj, t_opt opt)
{
	int	total;
	int	len;

	total = 0;
	len = get_hex_size(nbr);

	if (opt.sharp && nbr != 0)
		total += 2;
	if (opt.min_width > 0)
	{
		while (len + total < opt.min_width)
			total += print_char(' ');
	}
	if (opt.sharp && nbr != 0)
	{
		if (is_maj)
			print_str("0X");
		else
			print_str("0x");
	}
	if (is_maj)
		total += print_number_base(nbr, "0123456789ABCDEF");
	else
		total += print_number_base(nbr, "0123456789abcdef");
	return (total);
}
