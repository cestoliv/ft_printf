/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:19 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 14:39:11 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int total = ft_printf("char : %c, str : %s, pointer : %p, number : %d, unumber : %u, hex : %x, #hex : %#X, space : % d, plus : %+d, str_min_width : % 5s",
			'a',
			"Yo 42 !",
			LONG_MIN,
			-100,
			-5,
			-1,
			42,
			5,
			+2,
			"42"
	);

	printf("\ntotal : %d", total);
}
