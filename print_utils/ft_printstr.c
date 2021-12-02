/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:06:00 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 14:48:39 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur])
		write(1, &str[cur++], 1);
	return (cur);
}

int	ft_printstr(char *str, t_opt opt)
{
	int	cur;
	int len;

	cur = 0;
	if (!str)
		return (print_str("(null)"));
	len = ft_strlen(str);
	if (opt.min_width > 0)
	{
		while (cur + len < opt.min_width)
		{
			ft_printchar(' ');
			cur++;
		}
	}
	cur += print_str(str);
	return (cur);
}
