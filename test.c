/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:19 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/03 13:03:21 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int total = 0;
	/*
	total += ft_printf("char : %c, str : %s, pointer : %5p, number : %d, unumber : %u, hex : %x, #hex : %7x, space : |%    d|, plus : %+d, min_width : |%-5%|",
			'a',
			"Yo 42 !",
			0,
			-100,
			-5,
			-1,
			3735929054,
			64,
			+2,
			42
	);
	*/
	total += ft_printf(", string precision : %5s, num precision : %-1.8d",
			"-42",
			-10
	);
	printf("\ntotal : %d", total);
}
