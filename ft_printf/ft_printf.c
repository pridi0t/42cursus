/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 15:43:03 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_function(t_format *t, va_list p)
{
	int		result;
	char	*str;

	str = 0;
	if (t->specifier == '%')
		result = print_percent(t);
	else if (t->specifier == 'c')
		result = print_c(t, p);
	else if (t->specifier == 's')
		result = print_s(t, p);
	else if (t->specifier == 'p')
		result = print_p(t, p);
	else if (t->specifier == 'u')
		str = ft_uitoa(va_arg(p, unsigned int));
	else if (t->specifier == 'd' || t->specifier == 'i')
		str = ft_itoa(va_arg(p, int));
	else if (t->specifier == 'x')
		str = ft_itox(va_arg(p, unsigned int), 'a');
	else if (t->specifier == 'X')
		str = ft_itox(va_arg(p, unsigned int), 'A');
	if (str != 0)
		result = print_int(t, str);
	if (str != 0)
		free(str);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	t_format	t;
	va_list		p;
	int			i;
	int			result;

	i = -1;
	result = 0;
	va_start(p, str);
	while (str[++i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			set_format(&t, (char *)str, &i, p);
			result += call_function(&t, p);
		}
		else
		{
			write(1, &str[i], 1);
			result++;
		}
	}
	va_end(p);
	return (result);
}
