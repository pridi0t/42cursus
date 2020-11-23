/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:13:09 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/24 01:06:16 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_cstrlen(char *str, char c)
{
    int len;
    
    len = 0;
    while (str[len] != c && str[len] != 0)
        len++;
	if (len >= 0 && str[len] == 0 && str[len - 1] != c)
		return (-1);
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

char	*ft_cstrjoin(char const *s1, char const *s2, size_t s2size)
{
	size_t	s1len;
	size_t	s2len;
	char	*mem;

	s1len = ft_cstrlen((char *)s1, 0);
	s2len = ft_cstrlen((char *)s2, 0);
	mem = malloc(s1len + s2size + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, (s1len + 1));
	ft_strlcpy((mem + s1len), s2, (s2size + 1));
	return (mem);
}
