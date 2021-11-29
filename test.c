/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:19 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/29 18:49:02 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	//int varInt = 5;
	int total = ft_printf("char : %c, str : %s, pointer : %p",
			'a',
			"Yo 42 !",
			LONG_MIN
	);

	printf("\n%p\n", LONG_MIN);
	printf("\ntotal : %d", total);
}
