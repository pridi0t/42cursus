/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:28:13 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/12 11:46:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		numlen_check(long num)
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
		num /= 10;
		len++;
	}
	return (len);
}

char			*ft_uitoa(unsigned int n)
{
	long	num;
	int		len;
	int		flag;
	char	*mem;

	flag = 0;
	len = numlen_check(n);
	mem = malloc(len + 1);
	if (mem == 0)
		return (0);
	*(mem + len--) = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		*mem = '-';
		flag = 1;
	}
	while (len >= flag)
	{
		*(mem + len) = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (mem);
}
