/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:03:41 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/23 12:02:44 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		catoi(char *str, int *i)
{
	char	s[20];
	int		j;

	j = 0;
	ft_memset(s, 0, sizeof(s));
	while (ft_isdigit(str[*i]) != 0)
	{
		s[j] = str[*i];
		(*i)++;
		j++;
	}
	if (j == 0)
		return (-1);
	return (ft_atoi(s));
}

int		char_categorize(char c)
{
	if (c == '-' || c == '0' || c == '*')
		return (1);
	else if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
			c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (2);
	return (0);
}

void	init_format(t_format *t)
{
	t->flag1 = 0;
	t->flag2 = 0;
	t->width = -1;
	t->dot = 0;
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

int		set_format(t_format *t, char *str, int *i)
{
	init_format(t);
	if (set_flag(t, str, i) == -1)
		return (-1);
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
