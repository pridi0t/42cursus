/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:56:29 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/22 19:27:53 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	plen(char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) != c && *(s + i) != 0)
		{
			cnt++;
			while (*(s + i) != c && *(s + i) != 0)
				i++;
		}
		while (*(s + i) == c && *(s + i) != 0)
			i++;
	}
	return (cnt);
}

char	*strin(char *s, char c, size_t *i)
{
	size_t	len;
	char	*mem;

	len = 0;
	while (*(s + len) != c && *(s + len) != 0)
		len++;
	*i += len;
	mem = ft_substr(s, 0, len);
	if (mem == 0)
	{
		free(mem);
		return (0);
	}
	return (mem);
}

char	**ncheck(char **mem)
{
	mem = (char **)malloc(sizeof(char *) * 1);
	if (mem == 0)
		return (0);
	mem[0] = 0;
	return (mem);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		cnt;
	char	**mem;

	mem = 0;
	if (*s == 0 && c == 0)
		return (ncheck(mem));
	mem = (char **)malloc(sizeof(char *) * (plen((char *)s, c) + 1));
	if (mem == 0)
		return (0);
	i = 0;
	cnt = -1;
	while (*(s + i) != 0)
	{
		if (*(s + i) != c && *(s + i) != 0)
		{
			mem[++cnt] = strin(((char *)s + i), c, &i);
			if (mem[cnt] == 0)
				return (0);
		}
		while (*(s + i) == c && *(s + i) != 0)
			i++;
	}
	mem[++cnt] = 0;
	return (mem);
}
