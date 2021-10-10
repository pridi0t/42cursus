/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:43:27 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 19:25:54 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*increase_malloc(char *pstr, int cnt)
{
	char	*ret;

	ret = malloc(BUFFER_SIZE * cnt);
	ft_strlcpy(ret, pstr, ft_strlen(pstr) + 1);
	free(pstr);
	return (ret);
}

char	*ft_cstrjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*mem;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	mem = malloc(s1len + s2len + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, (s1len + 1));
	ft_strlcpy((mem + s1len), s2, (s2len + 1));
	free(s1);
	return (mem);
}

char	*ft_partstrdup(char *s1, int start, int end)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (char *)malloc(end - start + 2);
	if (mem == 0)
		return (0);
	while (start <= end)
	{
		if (s1[start] != -1)
			mem[i] = s1[start];
		start++;
		i++;
	}
	mem[i] = 0;
	return (mem);
}

char	**free_arr(char **arr)
{
	int	i;

	if (arr != NULL)
	{
		i = -1;
		while (arr[++i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
	}
	return (NULL);
}
