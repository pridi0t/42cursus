/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:31:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/08 12:54:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	result_d(t_format *t)
{

}

int	print_d(t_format *t, va_list p)
{
	int		*tmp;
	char	*str;

	if (t->flag1 ==)
	tmp = va_arg(p, int);
	if (tmp == 0)
		return (-1);
	*str = ft_itoa(tmp);
	if (t->precision < (int)ft_strlen(str))
	{
		if (t->width > (int)ft_strlen(str))

	}
}
