/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:31:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 12:24:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prtc(int n, char c)
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

int	d_ps(t_format *t, char *str)
{
	int result;

	result = 0;
	if (str[0] == '-')
	{
		write(1, "-", 1);
		str++;
	}
	result += prtc(t->precision - ft_strlen(str), '0');
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}

int	d_wps(t_format *t, char *str)
{
	if (t->flag == '-')
	{
		if (str[0] == '-')
		{
			write(1, "-", 1);
			str++;
			t->width--;
		}
		prtc(t->precision - ft_strlen(str), '0');
		write(1, str, ft_strlen(str));
		prtc(t->width - t->precision, ' ');
		return (t->width);
	}
	if (str[0] == '-')
		t->width--;
	prtc(t->width - t->precision, ' ');
	if (str[0] == '-')
	{
		write(1, "-", 1);
		str++;
	}
	prtc(t->precision - ft_strlen(str), '0');
	write(1, str, ft_strlen(str));
	return (t->width);
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

int	print_int(t_format *t, char *str)
{
	int		result;

	result = 0;
	if (str[0] == '0' && t->dot == 1)
		str = "";
	if (t->precision > (int)ft_strlen(str))
	{
		if (t->precision > t->width)
			return (d_ps(t, str));
		return (d_wps(t, str));
	}
	else if (t->width > (int)ft_strlen(str))
		return (d_wsp(t, str));
	write(1, str, ft_strlen(str));
	result += ft_strlen(str);
	return (result);
}
