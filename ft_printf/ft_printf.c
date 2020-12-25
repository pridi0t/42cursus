/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/25 12:47:31 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	call_function(t_format *t, va_list p)
{
	if (t->specifier == 'c')
		if (print_c(t, p) == -1)
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
			write(1, "%", 1);
			read = 0;
		}
		else if (read == 1)
		{
			if (set_format(&t, (char *)str, &i) == -1)
				return (-1);
			if (call_function(&t, p) == -1)
				return (-1);
			read = 0;
		}
		else
			write(1, &str[i], 1);
		i++;
	}

	va_end(p);

	/*
	printf("\n== result ==\n");
	printf("flag1 = %c, %d\n", t.flag1, t.flag1);
	printf("flag2 = %c, %d\n", t.flag2, t.flag2);
	printf("width = %d\n", t.width);
	printf("dot = %d\n", t.dot);
	printf("precision = %d\n", t.precision);
	printf("specifier = %c %d\n", t.specifier, t.specifier);
	*/

	return (0);
}
