/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:09:05 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 16:12:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		hexlen_check(long long num)
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

static void		convert(long long num, char *mem)
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
			*(mem + len) = ((num % 16) + 87);
		else
			*(mem + len) = ((num % 16) + '0');
		num /= 16;
		len--;
	}
}

char			*ft_ltox(long long n)
{
	long long	num;
	int			len;
	char		*mem;

	len = hexlen_check(n);
	mem = malloc(len + 1);
	if (mem == 0)
		return (0);
	*(mem + len--) = 0;
	num = n;
	if (n < 0)
		*mem = '-';
	convert(num, mem);
	return (mem);
}
