/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:53:11 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/31 20:48:22 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_result(int sign, int space, int len, char *str)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (sign == -1)
		write(1, (str + i), len);
	while (i < space)
	{
		write(1, " ", 1);
		i++;
	}
	if (sign == 0)
		write(1, (str + i), len);
	result += (space + len);
	return (result);
}

int	print_s(t_format *t, t_status *s, va_list p)
{
	char	*str;
	int		slen;
	int		lsort;
	
	i = 0;
	lsort = 0;
	s->result = 0;
	if (t->flag2 != 0 || (t-> flag1 != '-' && t->flag1 != '*'))
		return (-1);
	if (t->flag1 == '*')
	{
		t->width = va_arg(p, int);
		if (t->width <= 0)
			return (-1);
	}
	return (0);
}
