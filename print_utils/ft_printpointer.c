/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:44:10 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/03 11:16:54 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_long_as_hex(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total += print_long_as_hex(addr / 16);
		total += print_long_as_hex(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if ((addr % 16) > 9)
			c = ((addr % 16) + 87);
		write(1, &c, 1);
		total++;
	}
	return (total);
}

static int  get_hex_size(long unsigned addr)
{
    int     total;

    total = 0;
    if (addr >= 16)
    {
        total += get_hex_size(addr / 16);
        total += get_hex_size(addr % 16);
    }
    else
        total++;
    return (total);
}

int	ft_printpointer(void *ptr, t_opt opt)
{
	long	addr;
	int		total;
	int		len;

	addr = (long unsigned)ptr;
	total = 2;
	len = get_hex_size(addr);
	/*
	if (addr == 0)
		return (print_str("(nil)"));
	*/
	if (opt.min_width > 0)
	{
		while (len + total < opt.min_width)
			total += print_char(' ');
	}
	write(1, "0x", 2);
	total += print_long_as_hex(addr);
	return (total);
}
