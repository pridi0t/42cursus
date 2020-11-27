/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:13:09 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/28 03:27:23 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
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

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mem;

	len = ft_strlen((char *)s1);
	mem = (char *)malloc(len + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, len + 1);
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*mem;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s + start);
	mem = malloc(len + 1);
	if (mem == 0)
		return (0);
	if (slen >= len)
		ft_strlcpy(mem, (s + start), len + 1);
	else
		ft_strlcpy(mem, (s + start), slen + 1);
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*mem;

	if (s1 == 0)
		return (ft_strdup(""));
	else if (s2 == 0)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	mem = malloc(s1len + s2len + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, (s1len + 1));
	ft_strlcpy((mem + s1len), s2, (s2len + 1));
	return (mem);
}
