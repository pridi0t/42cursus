/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:23:37 by hyojang           #+#    #+#             */
/*   Updated: 2021/07/04 23:21:35 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_check(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = len_check(src);
	dstlen = len_check(dst);
	i = 0;
	while (*(src + i) != 0 && (i + 1 + dstlen) < dstsize)
	{
		*(dst + dstlen + i) = *(src + i);
		i++;
	}
	*(dst + dstlen + i) = 0;
	if (dstlen > dstsize)
		return (srclen + dstsize);
	return (srclen + dstlen);
}
