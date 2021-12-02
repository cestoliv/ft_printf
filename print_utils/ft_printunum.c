/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:11:31 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 14:47:38 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printunum(unsigned long nl)
{
	int				total;
	unsigned long	num;	

	total = 0;
	num = nl;
	if (nl < 0)
	{
		total += ft_printchar('-');
		num = -nl;
	}
	if (num > 100)
		total += ft_printunum(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += ft_printchar((num / 10) + '0');
	total += ft_printchar((num % 10) + '0');
	return (total);
}
