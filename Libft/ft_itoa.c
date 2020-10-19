/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:35:03 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/19 18:32:57 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	size_t	i;
	char	*mem;

	i = 0;
	len = 0;
	num = n;
	while (num > 0)
	{
		num %= 10;
		len++;
	}
	mem = malloc(len + 1);
	if (mem == 0)
		return (0);
	num = n;
	if (n < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		*(mem + i) = (num / 10) + '0';
		num /= 10;
		i++;
	}
	*(mem + i) = 0;
	return (mem);
}
