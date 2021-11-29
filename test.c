/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:51:19 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/29 15:26:15 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int varInt = 5;
	int total = ft_printf("char : %c, str : %s, pointer : %p", 'a', "Yo 42p!", &varInt);

	printf("\n%s : %p", &varInt, &varInt);
	printf("\ntotal : %d", total);
}
