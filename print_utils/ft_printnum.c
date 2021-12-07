/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:10:53 by ocartier          #+#    #+#             */
/*   Updated: 2021/12/07 11:55:04 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_number(long nl)
{
	int		total;
	long	num;	

	total = 0;
	num = nl;
	if (nl < 0)
	{
		total += print_char('-');
		num = -nl;
	}
	if (num > 100)
		total += print_number(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += print_char((num / 10) + '0');
	total += print_char((num % 10) + '0');
	return (total);
}

static int	number_of_digit(long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		cur++;
	while (num != 0)
	{
		num = num / 10;
		cur++;
	}
	return (cur);
}

static int	get_values(char	*prefix, int *len_prec, t_opt *opt, long nl)
{
	int		len;

	len = number_of_digit(nl);
	*len_prec = len;
	if (opt->precision > len)
		*len_prec = opt->precision;
	*prefix = '0';
	if (opt->zero && opt->dot && opt->zero_offset > opt->precision)
		*prefix = ' ';
	if (!opt->zero)
		*prefix = ' ';
	if (opt->zero)
		opt->min_width = opt->zero_offset;
	if (opt->precision > opt->min_width)
		opt->min_width = opt->precision;
	return (len);
}

static int	print_di(int len, long nl, t_opt opt)
{
	int	total;

	total = 0;
	if (nl == 0 && opt.min_width && opt.min_width < len)
		total += print_char(' ');
	else if (nl == 0 && opt.dot && !opt.precision && opt.min_width >= len)
		total += print_char(' ');
	else if (!(nl == 0 && opt.dot && !opt.precision))
		total += print_number(nl);
	return (total);
}

int	ft_printnum(long nl, t_opt opt)
{
	int		total;
	int		len;
	char 	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &opt, nl);

	if (nl < 0 && prefix == '0')
	{
		total += print_char('-');
		nl *= -1;
		if (opt.dot)
			len -= 2;
		else
			len -= 1;
	}
	/*
	else if (nl < 0)
	{
		len++;
		len_prec++;
	}
	*/

	while (len_prec + total < opt.min_width)
		total += print_char(prefix);
	
	if (nl < 0)
	{
		total += print_char('-');
		nl *= -1;
		if (opt.dot)
			len -= 2;
		else
			len -= 1;
	}

	while (len + total < opt.min_width)
		total += print_char('0');

	total += print_di(len, nl, opt);
	
	while (total < opt.offset)
		total += print_char(' ');
	/*
	if (opt.min_width > 0 && (!opt.minus || opt.dot))
	{
		if (opt.plus && nl >= 0)
			total++;
		if (opt.dot && nl < 0)
		{
			total += print_char('-');
			nl *= -1;
			len-=2;
		}
		while (len + total < opt.min_width)
			total += print_char(prefix);
		if (opt.plus && nl >= 0)
			total--;
	}
	if (opt.space && nl >= 0 && !opt.plus && !opt.dot)
		total += print_char(' ');
	else if (opt.plus && nl >= 0 && !opt.dot)
		total += print_char('+');
	total += print_number(nl);
	if (opt.minus && !opt.dot)
	{
		while (total < opt.min_width)
			total += print_char(' ');
	}
	*/
	return (total);
}
