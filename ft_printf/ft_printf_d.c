/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:31:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 03:17:26 by hyojang          ###   ########.fr       */
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
	int		num;
	int		result;

	result = 0;
	num = va_arg(p, int);
	str = ft_itoa(num);
	if (t->precision > (int)ft_strlen(str))
	{
		// precision > strlen, (ignore width)
		if (t->precision > t->width)
		{
			if (num < 0)
			{
				write(1, "-", 1);
				str++;
			}
			result += prtc(t->precision - ft_strlen(str), '0');
			write(1, str, ft_strlen(str));
			result += ft_strlen(str);
			return (result);
		}
		// width > precision > strlen
		if (t->flag == '-')
		{
			if (num < 0)
			{
				write(1, "-", 1);
				str++;
				t->width--;
			}
			prtc(t->precision - ft_strlen(str), '0');
			write(1, str, ft_strlen(str));
			prtc(t->width - t->precision, ' ');
		}
		if (t->flag != '-')
		{
			if (num < 0)
				t->width--;
			prtc(t->width - t->precision, ' ');
			if (num < 0)
			{
				write(1, "-", 1);
				str++;
			}
			prtc(t->precision - ft_strlen(str), '0');
			write(1, str, ft_strlen(str));
		}
		return (t->width);
	}
	else if (t->width > (int)ft_strlen(str))
	{
		// width > strlen > precision
		if (t->flag == '-')
			write(1, str, ft_strlen(str));
		if (t->flag == '0')
		{
			if (num < 0)
			{
				write(1, "-", 1);
				str++;
				t->width--;
			}
			result += prtc(t->width - ft_strlen(str), '0');
		}
		else
			result += prtc(t->width - ft_strlen(str), ' ');
		if (t->flag != '-')
			write(1, str, ft_strlen(str));
		return (t->width);
	}
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}
