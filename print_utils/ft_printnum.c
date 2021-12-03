/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:10:53 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 18:03:45 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_number(long nl)
{
	int		total;
	long	num;	

	total = 0;
	num = nl;
	if (nl < 0)
	{
		total += print_char('-');
		num = -nl;
	}
	if (num > 100)
		total += print_number(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += print_char((num / 10) + '0');
	total += print_char((num % 10) + '0');
	return (total);
}

static int	number_of_digit(long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		cur++;
	while (num != 0)
	{
		num = num / 10;
		cur++;
	}
	return (cur);
}

int	ft_printnum(long nl, t_opt opt)
{
	int	total;
	int	len;

	total = 0;
	len = number_of_digit(nl);
	if (opt.min_width > 0 && !opt.minus)
	{
		if (opt.plus && nl >= 0)
			total++;
		while (len + total < opt.min_width)
			total += print_char(' ');
		if (opt.plus && nl >= 0)
			total--;
	}
	if (opt.space && nl >= 0 && !opt.plus)
		total += print_char(' ');
	else if (opt.plus && nl >= 0)
		total += print_char('+');
	total += print_number(nl);
	if (opt.minus)
	{
		while (total < opt.min_width)
			total += print_char(' ');
	}
	return (total);
}
