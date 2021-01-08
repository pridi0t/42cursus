/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:31:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/08 20:31:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int prtc(int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	print_d(t_format *t, va_list p)
{
	char	*str;
	int		result;

	result = 0;
	if (t->width == -1)
		t->width = 0;
	if (t->precision == -1)
		t->precision = 0;
	if (t->flag1 == '*' || t->flag2 == '*')
		t->width = va_arg(p, int);
	if (t->flag3 == '*')
		t->precision = va_arg(p, int);
	str = ft_itoa(va_arg(p, int));
	if (t->precision > (int)ft_strlen(str))
	{
		if (t->precision > t->width)
		{
			if (t->flag3 == '-')
			{
				write(1, "-", 1);
				result ++;
			}
			result += prtc(t->precision - ft_strlen(str), '0');
			write(1, str, ft_strlen(str));
			result += ft_strlen(str);
			return (result);
		}
		result += prtc((t->width - t->precision - 1), ' ');
		if (t->flag3 == '-')
			write(1, "-", 1);
		else
			write(1, " ", 1);
		result++;
		result += prtc(t->precision - ft_strlen(str), '0');
		write(1, str, ft_strlen(str));
		result += ft_strlen(str);
		return (result);
	}
	if (t->width > (int)ft_strlen(str))
	{
		if (t->flag3 == '-')
		{
			write(1, "-", 1);
			result++;
		}
		else
			prtc(t->width - ft_strlen(str) - 1, ' ');
		result += prtc(t->width - ft_strlen(str), '0');
		write(1, str, ft_strlen(str));
		result += ft_strlen(str);
		return (result);
	}
	result += prtc((t->width - t->precision - 1), ' ');
	if (t->flag3 == '-')
		write(1, "-", 1);
	else
		write(1, " ", 1);
	result++;
	result += prtc(t->precision - ft_strlen(str), '0');
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}
