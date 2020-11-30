/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:13:09 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/30 18:05:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_cstrdup(const char *s1)
{
	size_t	len;
	char	*mem;

	if (s1[0] == 0)
	{
		mem = (char *)malloc(BUFFER_SIZE + 1);
		mem[0] = 0;
		return (mem);
	}
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
		return (ft_cstrdup(""));
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

char	*ft_cstrjoin(char *s1, char const *s2, int start, int end)
{
	size_t	s1len;
	size_t	s2len;
	char	*mem;

	if (s1 == 0)
		return (ft_cstrdup(""));
	else if (s2 == 0)
		return (ft_cstrdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	mem = malloc(s1len + s2len + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, (s1len + 1));
	ft_strlcpy((mem + s1len), s2 + start, (end - start + 1));
	free(s1);
	return (mem);
}
