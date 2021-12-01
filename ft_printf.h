/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:49:23 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/01 14:13:15 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printpointer(void *ptr);
int	ft_printnum(long nl);
int	ft_printunum(unsigned long nl);
int	ft_printbnum(int nl, char *base);

int	ft_strlen(char *str);
#endif
