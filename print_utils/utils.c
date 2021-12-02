/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:17:29 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 14:36:57 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(char *str)
{
	int	cur;

	cur = 0;
	if (str)
	{
		while (str[cur])
			cur++;
	}
	return (cur);
}

int	ft_atoi(const char *str, int *o_cur)
{
	int	cur;
	int	num;

	cur = 0;
	num = 0;
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
		(*o_cur)++;
	}
	return (num);
}
