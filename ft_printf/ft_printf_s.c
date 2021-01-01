/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:53:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/02 03:02:58 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_result(int sign, int space, int len, char *str)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (sign == -1)
		write(1, (str + i), len);
	while (i < space)
	{
		write(1, " ", 1);
		i++;
	}
	if (sign == 0)
		write(1, (str + i), len);
	result += (space + len);
	return (result);
}

int	print_s(t_format *t, t_status *s, va_list p)
{
	char	*str;
	
	s->result = 0;
	str = 0;
	if (t->flag2 != 0 || (t-> flag1 != '-' && t->flag1 != '*'))
		return (-1);
	else if (t->flag1 == '*')
	{
		t->width = va_arg(p, int);
		if (t->width <= 0)
			return (-1);
		str = va_arg(p, char *);
		if (str == 0)
			return (-1);
		if (t->width > (int)ft_strlen(str))
			return (print_result(0, (t->width - ft_strlen(str)), \
						ft_strlen(str), str));
	}
	str = va_arg(p, char *);
	if (str == 0)
	{
		write(1, "", 1);
		return (0);
	}
	else if (t->width != -1 && t->dot == 0)
	{
		if (t->width < (int)ft_strlen(str))
		{
			write(1, str, ft_strlen(str));
			return (ft_strlen(str));
		}
		if (t->flag1 == '-')
			return (print_result(-1, (t->width - ft_strlen(str)), \
						ft_strlen(str), str));
		return (print_result(0, (t->width - ft_strlen(str)), \
						ft_strlen(str), str));
	}
	else if (t->width != -1 && t->dot == 1)
	{
		write(1, str, t->width);
		return (t->width);
	}
	else if (t->width == -1 && t->precision != -1)
	{
		if (t->width > (int)ft_strlen(str))
		{
			write(1, str, ft_strlen(str));
			return (ft_strlen(str));
		}
		write(1, str, t->precision);
		return (t->precision);
	}
	else if (t->width != -1 && t->precision != -1)
	{
		if (t->width < t->precision)
		{
			write(1, str, ft_strlen(str));
			return (ft_strlen(str));
		}
		else if (t->width > t->precision)
		{
			if (t->flag1 == -1)
				return (print_result(-1, (t->width - t->precision), \
							t->precision, str));
			return (print_result(0, (t->width - t->precision), \
						t->precision, str));
		}
		if (t->width > (int)ft_strlen(str))
			return (print_result(-1, (t->width - ft_strlen(str)), \
						ft_strlen(str), str));
		write(1, str, t->width);
		return (t->width);
	}
	else if (t->width == -1 && t->precision == -1)
	{
		if (t-> flag1 == 0)
		{
			write(1, str, ft_strlen(str));
		}
		else if (t->flag1 == '-' && t->dot == 0)
		{
			write(1, str, ft_strlen(str));
			return (ft_strlen(str));
		}
		write(1, "", 1);
		return (0);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
