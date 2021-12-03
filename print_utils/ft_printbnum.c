/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:12:32 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/03 14:32:33 by ocartier         ###   ########lyon.fr   */
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
	int		total;
	int		len;
	char	prefix;

	if (opt.dot && opt.precision == 0 && nbr == 0)
		return (0);
	total = 0;
	prefix = ' ';
	if ((opt.dot || opt.zero) && !(opt.dot && opt.zero))
		prefix = '0';
	len = get_hex_size(nbr);
	if (opt.sharp && nbr != 0)
		len += 2;
	if (opt.precision < len)
		opt.precision = 0;
	while (len + total + opt.precision < opt.zero_offset)
		total += print_char('0');
	while (len + total < opt.min_width || len + total < opt.precision)
		total += print_char(prefix);
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
	while (total < opt.offset)
		total += print_char(' ');
	return (total);
}
