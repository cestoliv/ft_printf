/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:44:10 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 17:51:44 by ocartier         ###   ########.fr       */
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

int	ft_printpointer(void *ptr)
{
	long	addr;

	addr = (long unsigned)ptr;
	if (addr == 0)
		return (print_str("(nil)"));
	write(1, "0x", 2);
	return (print_long_as_hex(addr) + 2);
}
