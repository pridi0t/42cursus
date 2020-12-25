/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:22:51 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/25 19:52:42 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_c(t_format *t, t_status *s, va_list p)
{
	int		i;
	int		lsort;
	char	c;

	lsort = 0;
	i = 0;
	c = va_arg(p, int);
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
	if (t->flag1 == '-')
		lsort = 1;
	if (t->width >= 2)
	{
		while (i < t->width)
		{
			if (i == 0 && lsort == 1)
				write(1, &c, 1);
			else if (i == (t->width - 1) && lsort != 1)
				write(1, &c, 1);
			else
				write(1, " ", 1);
			(s->result)++;
			i++;
		}
	}
	else
	{
		write(1, &c, 1);
		(s->result)++;
	}
	return (s->result);
}
