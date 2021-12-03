/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:11:31 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 16:53:52 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_unumber(unsigned long nl)
{
	int				total;
	unsigned long	num;	

	total = 0;
	num = nl;
	if (num > 100)
		total += print_unumber(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += print_char((num / 10) + '0');
	total += print_char((num % 10) + '0');
	return (total);
}

static int	number_of_digit(unsigned long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		cur++;
	}
	return (cur);
}

int	ft_printunum(unsigned long nl, t_opt opt)
{
	int	total;
	int	len;

	total = 0;
	if (opt.min_width > 0)
	{
		len = number_of_digit(nl);
		while (len + total < opt.min_width)
			total += print_char(' ');
	}
	total += print_unumber(nl);
	return (total);
}
