/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:22:51 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 19:23:45 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	result_c(t_format *t, char *c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if (t->width >= 2)
	{
		while (i < t->width)
		{
			if (i == 0 && t->flag == '-')
				write(1, c, 1);
			else if (i == (t->width - 1) && t->flag != '-')
				write(1, c, 1);
			else
				write(1, " ", 1);
			result++;
			i++;
		}
		return (result);
	}
	write(1, c, 1);
	result++;
	return (result);
}

int	print_c(t_format *t, va_list p)
{
	char	c;

	c = va_arg(p, int);
	if (t->width < 0 || t->precision != 0)
		return (-1);
	return (result_c(t, &c));
}
