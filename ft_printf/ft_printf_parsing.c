/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:03:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/05 20:27:36 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *t)
{
	t->flag1 = 0;
	t->flag2 = 0;
	t->width = -1;
	t->dot = 0;
	t->flag3 = 0;
	t->precision = -1;
	t->specifier = 0;
}

int		set_flag(t_format *t, char *str, int *i)
{
	if (char_categorize(str[*i]) == 1)
	{
		t->flag1 = str[*i];
		(*i)++;
		if (char_categorize(str[*i]) == 1 && t->flag1 != 0)
		{
			t->flag2 = str[*i];
			(*i)++;
		}
		if (char_categorize(str[*i]) == 1 && t->flag2 != 0)
			return (-1);
	}
	return (0);
}

int		set_other(t_format *t, char *str, int *i)
{
	if (ft_isdigit(str[*i]) != 0 && str[*i] != '0')
	{
		t->width = catoi(str, i);
		if (t->width == -1 || t->width == 0)
			return (-1);
	}
	if (str[*i] == '.')
	{
		t->dot = 1;
		(*i)++;
	}
	if (str[*i] == '*')
	{
		t->flag3 = str[*i];
		(*i)++;
	}
	if (ft_isdigit(str[*i]) != 0 && t->dot == 1)
	{
		t->precision = catoi(str, i);
		if (t->precision == -1)
			return (-1);
	}
	if (char_categorize(str[*i]) != 2)
		return (-1);
	t->specifier = str[*i];
	return (0);
}

int		set_format(t_format *t, char *str, int *i)
{
	init_format(t);
	if (set_flag(t, str, i) == -1)
		return (-1);
	if (set_other(t, str, i) == -1)
		return (-1);
	return (0);
}
