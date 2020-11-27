/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:42:41 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/28 06:07:58 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		find_new(char const *s)
{
	int idx;

	idx = 0;
	while (s[idx] != 0)
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		tmp_exception(char ***line, char **tmp)
{
	size_t	len;
	int		nidx;

	if (*tmp == 0)
		*tmp = ft_strdup("");
	len = ft_strlen(*tmp);
	if ((nidx = find_new(*tmp)) == 0)
	{
		**line = ft_strdup("");
		*tmp = ft_substr(*tmp, nidx + 1, len);
		return (1);
	}
	else if (nidx > 0 && len != 0)
	{
		**line = ft_substr(*tmp, 0, nidx);
		*tmp = ft_substr(*tmp, nidx + 1, len - nidx + 1);
		return (1);
	}
	else if (*tmp != 0)
	{
		**line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			end;
	int			nidx;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (tmp_exception(&line, &tmp) == 1)
		return (1);
	while ((end = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[end] = 0;
		if ((nidx = find_new(buf)) != -1)
		{
			*line = ft_cstrjoin(*line, buf, 0, nidx);
			tmp = ft_substr(buf, nidx + 1, end - nidx + 1);
			return (1);
		}
		*line = ft_cstrjoin(*line, buf, 0, end);
	}
	return (0);
}
