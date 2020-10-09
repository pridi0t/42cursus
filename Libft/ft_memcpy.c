/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:45 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/09 14:56:16 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	if (dst != src && n != 0)
	{
		i = 0;
		dst2 = (char *)dst;
		src2 = (char *)src;
		while (i < n)
		{
			*(dst2 + i) = *(src2 + i);
			i++;
		}
	}
	return (dst);
}
