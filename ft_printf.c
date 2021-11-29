/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:54 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/29 15:09:04 by ocartier         ###   ########lyon.fr   */
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
			cur++;
		}
		else
			total += ft_printchar(str[cur]);
		cur++;
	}
	/*
    for (int i=0; i < 4; i++)
        total = total + va_arg(params, int);
	*/
    va_end(params);
	return (total);
}
