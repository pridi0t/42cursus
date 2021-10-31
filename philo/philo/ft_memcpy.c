/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:45 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 00:10:20 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst != src && n != 0)
	{
		i = 0;
		dst2 = (unsigned char *)dst;
		src2 = (unsigned char *)src;
		while (i < n)
		{
			*(dst2 + i) = *(src2 + i);
			i++;
		}
	}
	return (dst);
}
