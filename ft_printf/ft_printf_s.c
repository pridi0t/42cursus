/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:53:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/05 20:30:43 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	s_result(t_format *t, int space, int size, char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if (t->flag1 == '-')
		write(1, str, size);
	while (i < space)
	{
		write(1, " ", 1);
		i++;
		result++;
	}
	if (t->flag1 != '-')
		write(1, str, size);
	result += size;
	return (result);
}

int	print_s(t_format *t, va_list p)
{
	char	*str;

	str = 0;
	if (t->width == -1)
		t->width = 0;
	if (t->precision == -1)
		t->precision = 0;
	if (t->flag1 == '*' || t->flag2 == '*')
		t->width = va_arg(p, int);
	if (t->flag3 == '*')
	{
		t->precision = va_arg(p, int);
		if (t->precision < 0)
			str = "(null)";
		return (s_result(t, 0, ft_strlen(str), str));
	}
	if ((str = va_arg(p, char *)) == 0)
		str = "(null)";
	if (t->precision == 0 && t->dot == 0 && (t->width <= (int)ft_strlen(str)))
		return (s_result(t, 0, ft_strlen(str), str));
	if (t->precision == 0 && t->dot == 0 && (t->width > (int)ft_strlen(str)))
		return (s_result(t, (t->width - ft_strlen(str)), ft_strlen(str), str));
	if (t->width == 0 && t->dot == 1 && (t->precision > (int)ft_strlen(str)))
		return (s_result(t, 0, ft_strlen(str), str));
	if (t->precision > (int)ft_strlen(str))
	{
		if (t->width < (int)ft_strlen(str))
			return (s_result(t, 0, ft_strlen(str), str));
		return (s_result(t, (t->width - ft_strlen(str)), \
					ft_strlen(str), str));
	}
	else if (t->precision <= (int)ft_strlen(str))
	{
		if (t->dot == 1 && (t->width > t->precision))
			return (s_result(t, (t->width - t->precision), t->precision, str));
		if (t->dot == 1 && (t->width <= t->precision))
			return (s_result(t, 0, t->precision, str));
		else if (t->dot == 1 && t->width == 0 && t->precision != 0)
			return (s_result(t, 0, t->precision, str));
	}
	return (s_result(t, 0, ft_strlen(str), str));
}
