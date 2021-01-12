/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:35:03 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 12:45:11 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		hexlen_check(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void		convert(long num, char c, char *mem)
{
	int len;
	int flag;

	len = hexlen_check(num) - 1;
	flag = 0;
	if (num < 0)
	{
		num *= -1;
		flag = 1;
	}
	while (len >= flag)
	{
		if ((num % 16) >= 10)
			*(mem + len) = ((num % 16) + (c - 10));
		else
			*(mem + len) = ((num % 16) + '0');
		num /= 16;
		len--;
	}
}

char			*ft_itox(unsigned int n, char c)
{
	long	num;
	int		len;
	char	*mem;

	len = hexlen_check(n);
	mem = malloc(len + 1);
	if (mem == 0)
		return (0);
	*(mem + len--) = 0;
	num = n;
	if (n < 0)
		*mem = '-';
	convert(num, c, mem);
	return (mem);
}
