/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:54 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/01 14:16:03 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int	ft_printf(const char *str, ...)
{
    va_list	params;
    int		cur;
	int		total;

    cur = 0;
	total = 0;
    va_start(params, str);
	while (str[cur])
	{
		if (str[cur] == '%')
		{
			if (str[cur + 1] == 'c')
				total += ft_printchar(va_arg(params, int));
			else if (str[cur + 1] == 's')
				total += ft_printstr(va_arg(params, char *));
			else if (str[cur + 1] == 'p')
				total += ft_printpointer(va_arg(params, void *));
			else if (str[cur + 1] == 'd' || str[cur + 1] == 'i')
				total += ft_printnum(va_arg(params, int));
			else if (str[cur + 1] == 'u')
				total += ft_printunum(va_arg(params, unsigned int));
			else if (str[cur + 1] == 'x')
				total += ft_printbnum(va_arg(params, int), "0123456789abcdef");
			else if (str[cur + 1] == 'X')
				total += ft_printbnum(va_arg(params, int), "0123456789ABCDEF");
			else if (str[cur + 1] == '%')
				total += ft_printchar('%');
			cur++;
		}
		else
			total += ft_printchar(str[cur]);
		cur++;
	}
    va_end(params);
	return (total);
}
