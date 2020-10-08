/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:45 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/09 00:14:14 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i;
	char * dst2;
	char * src2;

	if (dst != src)
	{
		i = 0;
		dst2 = dst;
		src2 = src;
		while (i < n)
		{
			*(dst2 + i) = *(src2 + i);
			i++;
		}
	}
}
