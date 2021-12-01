/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:19 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/01 14:06:28 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	//int varInt = 5;
	int total = ft_printf("char : %c, str : %s, pointer : %p, number : %d, unumber : %u, hex : %x",
			'a',
			"Yo 42 !",
			LONG_MIN,
			-100,
			-5,
			-1
	);

	printf("\n%x", -1);

	printf("\ntotal : %d", total);
}
