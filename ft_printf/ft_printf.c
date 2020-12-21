/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/21 14:09:06 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	catoi(char *str[], int *i)
{
	char	s[20];
	int		j;
	
	j = 0;
	ft_memset(s, 0, sizeof(s));
	while (ft_isdigit(*str[*i]) != 0)
	{
		s[j] = *str[*i];
		(*i)++;
		j++;
	}
	if (j == 0)
		return (-1);
	return (ft_atoi(s));
}

int	char_categorize(char c)
{
	if (c == '-' || c == '0' || c == '*')
		return (1);
	else if(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'\
			|| c == 'u' || c == 'x' || c == 'X')
		return (2);
	return (0);
}

int	set_format(t_format *t, char *str[], int *i)
{
	int tmp;

	tmp = 0;
	t->flag1 = 0;
	t->flag2 = 0;
	t->width = -1;
	t->dot = 0;
	t->precision = -1;
	t->specifier = 0;
	if (char_categorize(*str[*i]) == 1)
	{
		t->flag1 = *str[*i];
		(*i)++;
		if (char_categorize(*str[*i]) == 1 && t->flag1 != 0)
		{
			t->flag2 = *str[*i];
			(*i)++;
		}
		if (char_categorize(*str[*i]) == 1 && t->flag2 != 0)
			return (-1);
	}
	if (ft_isdigit(*str[*i]) != 0 && *str[*i] != '0')
	{
		tmp = catoi(str, i);
		if (tmp == -1 || tmp == 0)
			return (-1);
	}
	if (*str[*i] == '.')
	{
		if (tmp > 0)
		{
			t->width = tmp;
			tmp = 0;
		}
		t->dot = 1;
		(*i)++;
	}
	if (ft_isdigit(*str[*i]) != 0 && t->dot == 1)
	{
		t->precision = catoi(str, i);
		if (t-> precision == -1)
			return (-1);
		(*i)++;
	}
	if (char_categorize(*str[*i]) == 2)
		t->specifier = *str[*i];
	if (t->specifier == 0)
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_format	t;
	va_list		p;
	int			i;
	int			read;

	i = 0;
	read = 0;
	va_start(p, str);
	while (str[i] != 0)
	{
		if (str[i] == '%' && read == 0)
			read = 1;
		else if (str[i] == '%' && read == 1)
		{
			i++;
			if (set_format(&t, str, &i) == -1)
				return (-1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}

	va_end(p);

	printf("== result ==\n");
	printf("flag1 = %c, %d\n", t.flag1, t.flag1);
	printf("flag2 = %c, %d\n", t.flag2, t.flag2);
	printf("width = %d\n", t.width);
	printf("dot = %d\n", t.dot);
	printf("precision = %d\n", t.precision);
	printf("specifier = %c %d\n", t.specifier, t.specifier);
	
	return (0);
}
