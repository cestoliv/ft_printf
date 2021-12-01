/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:54 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/01 14:31:38 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process(const char *str, va_list *params)
{
	int	total;

	total = 0;
	if (str[1] == 'c')
		total += ft_printchar(va_arg(*params, int));
	else if (str[1] == 's')
		total += ft_printstr(va_arg(*params, char *));
	else if (str[1] == 'p')
		total += ft_printpointer(va_arg(*params, void *));
	else if (str[1] == 'd' || str[1] == 'i')
		total += ft_printnum(va_arg(*params, int));
	else if (str[1] == 'u')
		total += ft_printunum(va_arg(*params, unsigned int));
	else if (str[1] == 'x')
		total += ft_printbnum(va_arg(*params, int), "0123456789abcdef");
	else if (str[1] == 'X')
		total += ft_printbnum(va_arg(*params, int), "0123456789ABCDEF");
	else if (str[1] == '%')
		total += ft_printchar('%');
	return (total);
}

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
			total += process(str + cur, &params);
			cur++;
		}
		else
			total += ft_printchar(str[cur]);
		cur++;
	}
	va_end(params);
	return (total);
}
