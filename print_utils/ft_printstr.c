/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:06:00 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/29 15:28:28 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printstr(char *str)
{
	int	cur;

	cur = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[cur])
		write(1, &str[cur++], 1);
	return (cur);
}
