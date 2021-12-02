/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:10:53 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 14:47:59 by ocartier         ###   ########lyon.fr   */
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
		total += ft_printchar('-');
		num = -nl;
	}
	if (num > 100)
		total += print_number(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += ft_printchar((num / 10) + '0');
	total += ft_printchar((num % 10) + '0');
	return (total);
}

int	ft_printnum(long nl, t_opt opt)
{
	int	total;

	total = 0;
	if (opt.space && nl >= 0 && !opt.plus)
		total += ft_printchar(' ');
	else if (opt.plus && nl >= 0)
		total += ft_printchar('+');
	total += print_number(nl);
	return (total);
}
