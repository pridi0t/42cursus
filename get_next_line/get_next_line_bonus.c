/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:42:41 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/30 18:04:48 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	len = ft_strlen(*tmp);
	if ((nidx = find_new(*tmp)) == 0)
	{
		**line = ft_cstrdup("");
		ft_strlcpy(*tmp, *tmp + nidx + 1, len);
		return (1);
	}
	else if (nidx > 0 && len != 0)
	{
		**line = ft_substr(*tmp, 0, nidx);
		ft_strlcpy(*tmp, *tmp + nidx + 1, len - nidx + 1);
		return (1);
	}
	else if (*tmp != 0)
	{
		**line = ft_cstrdup(*tmp);
		free(*tmp);
		*tmp = 0;
	}
	return (0);
}

int		rcheck(int end, char ***line)
{
	if (end < 0)
	{
		**line = 0;
		return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			end;
	int			nidx;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	if (tmp[fd] == 0)
		tmp[fd] = ft_cstrdup("");
	if (tmp_exception(&line, &tmp[fd]) == 1)
		return (1);
	while ((end = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[end] = 0;
		if ((nidx = find_new(buf)) != -1)
		{
			*line = ft_cstrjoin(*line, buf, 0, nidx);
			tmp[fd] = ft_substr(buf, nidx + 1, end - nidx + 1);
			return (1);
		}
		*line = ft_cstrjoin(*line, buf, 0, end);
	}
	return (rcheck(end, &line));
}
