/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:54 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 13:25:59 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_normal(const char *str, va_list *params)
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

int	process_sharp(const char *str, va_list *params)
{
	int	total;
	int	num;

	total = 0;
	num = va_arg(*params, int);
	if (str[1] == 'x' && num != 0)
		total += ft_printstr("0x");
	else if (str[1] == 'X' && num != 0)
		total += ft_printstr("0X");
	if (str[1] == 'x')
		total += ft_printbnum(num, "0123456789abcdef");
	else if (str[1] == 'X')
		total += ft_printbnum(num, "0123456789ABCDEF");
	return (total);
}

int	process(const char *str, va_list *params, int *cur)
{
	int	total;

	total = 0;
	if (str[(*cur) + 1] == '#')
	{
		total += process_sharp(str + (*cur) + 1, params);
		(*cur)++;
	}
	else
		total += process_normal(str + (*cur), params);
	(*cur)++;
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
			total += process(str, &params, &cur);
		else
			total += ft_printchar(str[cur]);
		cur++;
	}
	va_end(params);
	return (total);
}
