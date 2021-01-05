/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/05 20:19:31 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	call_function(t_format *t, t_status *s, va_list p)
{
	if (t->specifier == 'c')
		return (print_c(t, s, p));
	if (t->specifier == 's')
		return (print_s(t, p));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_format	t;
	t_status	s;
	va_list		p;
	int			i;
	int			tmp;

	i = 0;
	s.read = 0;
	s.result = 0;
	va_start(p, str);
	while (str[i] != 0)
	{
		if (str[i] == '%' && s.read == 0)
			s.read = 1;
		else if (str[i] == '%' && s.read == 1)
		{
			write(1, "%", 1);
			s.read = 0;
			s.result++;
		}
		else if (s.read == 1)
		{
			if (set_format(&t, (char *)str, &i) == -1)
				return (-1);
			tmp = call_function(&t, &s, p);
			if (tmp == -1)
				return (-1);
			s.result += tmp;
			s.read = 0;
		}
		else
		{
			write(1, &str[i], 1);
			s.result++;
		}
		i++;
	}
	va_end(p);
	return (s.result);
}
