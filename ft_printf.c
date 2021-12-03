/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:54 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 17:57:11 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_normal(const char *str, va_list *params, t_opt opt)
{
	int	total;

	total = 0;
	if (str[1] == 'c')
		total += ft_printchar(va_arg(*params, int), opt);
	else if (str[1] == 's')
		total += ft_printstr(va_arg(*params, char *), opt);
	else if (str[1] == 'p')
		total += ft_printpointer(va_arg(*params, void *));
	else if (str[1] == 'd' || str[1] == 'i')
		total += ft_printnum(va_arg(*params, int), opt);
	else if (str[1] == 'u')
		total += ft_printunum(va_arg(*params, unsigned int), opt);
	else if (str[1] == 'x')
		total += ft_printbnum(va_arg(*params, int), 0, opt);
	else if (str[1] == 'X')
		total += ft_printbnum(va_arg(*params, int), 1, opt);
	else if (str[1] == '%')
		total += print_char('%');
	return (total);
}

int	process(const char *str, va_list *params, int *cur)
{
	int		total;
	t_opt	opt;

	opt.sharp = 0;
	opt.space = 0;
	opt.plus = 0;
	opt.minus = 0;
	opt.min_width = 0;
	total = 0;
	while (in_set(str[(*cur) + 1], "# +-"))
	{
		if (str[(*cur) + 1] == '#')
			opt.sharp = 1;
		else if (str[(*cur) + 1] == ' ')
			opt.space = 1;
		else if (str[(*cur) + 1] == '+')
			opt.plus = 1;
		else if (str[(*cur) + 1] == '-')
			opt.minus = 1;
		(*cur)++;
	}
	opt.min_width = ft_atoi(str + (*cur) + 1, cur);
	total += process_normal(str + (*cur), params, opt);
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
			total += print_char(str[cur]);
		cur++;
	}
	va_end(params);
	return (total);
}
