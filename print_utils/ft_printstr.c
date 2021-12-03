/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:06:00 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 18:01:26 by ocartier         ###   ########.fr       */
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
	len = ft_strlen(str);
	if (!str)
		len = 6;
	if (opt.min_width > 0)
	{
		while (cur + len < opt.min_width)
			cur += print_char(' ');
	}
	if (!str)
		return (cur += print_str("(null)"));
	cur += print_str(str);
	return (cur);
}
