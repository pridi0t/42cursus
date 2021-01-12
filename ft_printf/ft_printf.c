/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 16:02:34 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_function(t_format *t, va_list p)
{
	char *str;

	str = 0;
	if (t->specifier == '%')
		return (print_percent(t));
	if (t->specifier == 'c')
		return (print_c(t, p));
	if (t->specifier == 's')
		return (print_s(t, p));
	if (t->specifier == 'p')
		return (print_p(t, p));
	if (t->specifier == 'u')
		str = ft_uitoa(va_arg(p, unsigned int));
	else if (t->specifier == 'd' || t->specifier == 'i')
		str = ft_itoa(va_arg(p, int));
	else if (t->specifier == 'x')
		str = ft_itox(va_arg(p, unsigned int), 'a');
	else if (t->specifier == 'X')
		str = ft_itox(va_arg(p, unsigned int), 'A');
	return (print_int(t, str));
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
