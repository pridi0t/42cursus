/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:58:32 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 19:21:34 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_format *t)
{
	int i;
	int result;

	i = -1;
	result = 0;
	if (t->width >= 2)
	{
		while (++i < t->width)
		{
			if (i == 0 && t->flag == '-')
				write(1, "%", 1);
			else if (i == (t->width - 1) && t->flag != '-')
				write(1, "%", 1);
			else if (t->flag == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
			result++;
		}
		return (result);
	}
	write(1, "%", 1);
	return (1);
}
