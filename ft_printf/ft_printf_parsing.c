/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:03:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 00:45:53 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_set1(t_format *t, char *str, int *i, va_list p)
{
	if (str[*i] == '-' || str[*i] == '0')
	{
		t->flag = str[*i];
		(*i)++;
		if (t->flag == '0' && str[*i] == '-')
		{
			t->flag = str[*i];
			(*i)++;
		}
	}
	if (str[*i] == '*')
		t->width = va_arg(p, int);
	else if (ft_isdigit(str[*i]) != 0)
		t->width = catoi(str, i);
	if (str[*i] == '.')
	{
		t->dot = 1;
		(*i)++;
	}
}

int		t_set2(t_format *t, char *str, int *i, va_list p)
{
	if (str[*i] == '*')
	{
		t->precision = va_arg(p, int);
		(*i)++;
		if (t->precision < 0)
		{
			t->dot = 0;
			t->precision = 0;
		}
	}
	else if (ft_isdigit(str[*i]) != 0 || str[*i] == '-')
		t->precision = catoi(str, i);
	if (isspecifier(str[*i]) != 1)
		return (-1);
	t->specifier = str[*i];
	return (0);
}

int		set_format(t_format *t, char *str, int *i, va_list p)
{
	t->flag = 0;
	t->width = -1;
	t->dot = 0;
	t->precision = -1;
	t->specifier = 0;
	t_set1(t, str, i, p);
	if (t_set2(t, str, i, p) == -1)
		return (-1);
	if (t->width == -1)
		t->width = 0;
	if (t->precision == -1)
		t->precision = 0;
	return (0);
}
