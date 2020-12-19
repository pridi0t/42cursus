/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/19 17:13:53 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	catoi(char *str[], int *i)
{
	char	s[20];
	int		i;
	
	i = 0;
	s = ft_memset(s, 0, sizeof(s));
	while (ft_isdigit(str[*i]) != 0 && i < sizeof(s))
	{
		s[i] = str[*i];
		(*i)++;
	}
	if (ft_strlen(s) == 0 || ft_atoi(s) == 0)
		return (-1);
	return (ft_atoi(s));
}

int	set_format(t_format *t, char *str[], int *i)
{
	int tmp;

	t->flag = 0;
	t->width = -1;
	t->precision = -1;
	t->specifier = 0;
	if (str[*i] == '-' || str[*i] == '0' || str[*i] == '*')
	{
		t->flag = str[*i];
		(*i)++;
		if (str[*i] == '0' && t->flag != 0)
			return (-1);
	}
	if (ft_isdigit(str[*i]) != 0 && str[*i] != '0')
	{
		tmp = catoi(t, str, i);
		(*i)++;
	}
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
	while (str[i] != 0 && p != 0)
	{
		if (str[i] == '%' && read == 0)
			read = 1;
		else if (args[i] == '%' && read == 1)
		{
			if (set_format(&t, &str, &(++i)) == -1)
				return (-1);
		}
		else
			write(1, &args[i], 1);
		i++;
	}
	return (0);
}
