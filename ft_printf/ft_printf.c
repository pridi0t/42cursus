/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 00:49:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_function(t_format *t, va_list p)
{
	if (t->specifier == 'c')
		return (print_c(t, p));
	if (t->specifier == 's')
		return (print_s(t, p));
	if (t->specifier == 'd')
		return (print_d(t, p));
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
		else if (s.read == 1)
		{
			if (set_format(&t, (char *)str, &i, p) == -1)
				return (-1);
			tmp = call_function(&t, p);
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
