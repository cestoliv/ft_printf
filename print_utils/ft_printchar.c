/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:58:41 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 14:53:10 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_printchar(char c, t_opt opt)
{
	int	cur;

	cur = 1;
	if (opt.min_width > 0)
	{
		while (cur + len < opt.min_width)
		{
			
		}
	}
}
