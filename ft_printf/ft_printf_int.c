/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:31:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 18:54:56 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_ps(t_format *t, char *str)
{
	int result;

	result = 0;
	if (str[0] == '-')
	{
		write(1, "-", 1);
		str++;
		result++;
	}
	result += rc(t->precision - ft_strlen(str), '0');
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}

int	d_mwps(t_format *t, char *str)
{
	int result;

	result = 0;
	if (str[0] == '-')
	{
		write(1, "-", 1);
		str++;
		t->width--;
		result++;
	}
	result += rc(t->precision - ft_strlen(str), '0');
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	result += rc(t->width - t->precision, ' ');
	return (result);
}

int	d_wps(t_format *t, char *str)
{
	int result;

	result = 0;
	if (str[0] == '-')
	{
		t->width--;
	}
	result += rc(t->width - t->precision, ' ');
	if (str[0] == '-')
	{
		write(1, "-", 1);
		str++;
		result++;
	}
	result += rc(t->precision - ft_strlen(str), '0');
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}

int	d_wsp(t_format *t, char *str)
{
	int result;

	result = 0;
	if (t->flag == '0' && t->precision != 0)
		t->flag = 0;
	if (t->flag == '-')
		write(1, str, ft_strlen(str));
	if (t->flag == '0')
	{
		if (str[0] == '-')
		{
			write(1, "-", 1);
			str++;
			result++;
			t->width--;
		}
		result += rc(t->width - ft_strlen(str), '0');
	}
	else
		result += rc(t->width - ft_strlen(str), ' ');
	if (t->flag != '-')
		write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}

int	print_int(t_format *t, char *str)
{
	int		result;

	result = 0;
	if (str[0] == '0' && t->dot == 1)
		str = "";
	if (t->precision >= (int)ft_strlen(str))
	{
		if (t->precision > t->width)
			return (d_ps(t, str));
		if (t->flag == '-')
			return (d_mwps(t, str));
		return (d_wps(t, str));
	}
	else if (t->width > (int)ft_strlen(str))
		return (d_wsp(t, str));
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}
