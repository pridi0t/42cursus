/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:12:01 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/11 17:37:00 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	i = -1;
	while (*(src + srclen) != 0)
		srclen++;
	if (dstsize == 0)
		return (srclen);
	if (srclen < dstsize)
	{
		while (*(src + ++i) != 0)
			*(dst + i) = *(src + i);
	}
	else
	{
		while (++i < (dstsize - 1))
			*(dst + i) = *(src + i);
	}
	*(dst + i) = 0;
	return (srclen);
}
