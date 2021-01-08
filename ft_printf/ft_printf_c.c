/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:22:51 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/08 11:05:57 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	excep_c(t_format *t)
{
	if (t->flag1 == '0' || t->flag1 == '*')
		return (-1);
	if (t->flag2 == '0' || t->flag2 == '*')
		return (-1);
	else if (t->flag2 == '-' && t->flag1 != '-')
		return (-1);
	if (t->dot != 0 && t->precision != -1)
		return (-1);
	if (t->precision != -1 || t->width == 0)
		return (-1);
	return (0);
}

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
			if (i == 0 && t->flag1 == '-')
				write(1, c, 1);
			else if (i == (t->width - 1) && t->flag1 != '-')
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
	if (excep_c(t) == -1)
		return (-1);
	return (result_c(t, &c));
}
