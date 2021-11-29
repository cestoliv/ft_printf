/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:44:10 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/29 18:48:58 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int print_long_as_hex(long addr)
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

int	ft_printpointer(void *ptr)
{
	long	addr;

	addr = (long)ptr;
	write(1, "0x", 2);
	return (print_long_as_hex(addr) + 2);
}
