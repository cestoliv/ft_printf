/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:58:41 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 15:37:08 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_printchar(char c, t_opt opt)
{
	int	cur;
	int	total;

	total = 0;
	cur = 1;
	if (opt.min_width > 0)
	{
		while (cur < opt.min_width)
		{
			total += print_char(' ');
			cur++;
		}
	}
	total += print_char(c);
	return (total);
}
