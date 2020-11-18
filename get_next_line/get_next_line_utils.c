/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:13:09 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/19 04:01:15 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_cstrlen(char *str, char c)
{
    size_t len;
    
    len = 0;
    while (str[len] != c && str[len] != 0)
        len++;
    return (len);
}

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

size_t	len_check(const char *str)
{
	size_t i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t dstlen;
	size_t i;

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

char	*ft_cstrjoin(char const *s1, char const *s2, size_t s2Size)
{
	size_t	s1len;
	size_t	s2len;
	char	*mem;

	s1len = ft_cstrlen((char *)s1, 0);
	s2len = ft_cstrlen((char *)s2, 0);
	mem = malloc(s1len + s2Size + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, (s1len + 1));
	ft_strlcpy((mem + s1len), s2, (s2Size + 1));
	return (mem);
}
