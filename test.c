/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:19 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/02 17:57:41 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int total = ft_printf("char : %c, str : %s, pointer : %p, number : %d, unumber : %u, hex : %x, #hex : %#X, space : |%    d|, plus : %+d, min_width : |%-5%|",
			'a',
			"Yo 42 !",
			0,
			-100,
			-5,
			-1,
			42,
			64,
			+2,
			42
	);
	ft_printf("\n");
	ft_printf("%-5%");
	printf("\ntotal : %d", total);
}
