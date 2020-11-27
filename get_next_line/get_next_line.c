/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:42:41 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/27 19:09:18 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

int 	get_next_line(int fd, char **line)
{
    static char *tmp;
    char        buf[BUFFER_SIZE + 1];
	size_t		len;
	int			nidx;
	int			end;

    if (fd == -1 || BUFFER_SIZE <= 0)
        return (-1);
	if (tmp == 0)
		tmp = ft_strdup("");
	len = ft_strlen(tmp);
	if ((nidx = find_new(tmp)) == 0)
	{
		write(1,"1",1);
		*line = ft_strdup("");
		tmp = ft_substr(tmp, nidx + 1, len);
		return (1);
	}
	else if (nidx > 0 && len != 0)
	{
		write(1,"2",1);
		*line = ft_substr(tmp, 0, nidx);
		tmp = ft_substr(tmp, nidx + 1, len - nidx + 1);
		return (1);
	}
	*line = ft_strdup(tmp);
	while ((end = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		write(1,"3",1);
		buf[end] = 0;
		if ((nidx = find_new(buf)) != -1)
		{	
			*line = ft_strjoin(*line, ft_substr(buf, 0, nidx));
			tmp = ft_substr(buf, nidx + 1, end - nidx + 1);
			return (1);
		}
		*line = ft_strjoin(*line, buf);
		if (end < BUFFER_SIZE)
			return (0);
	}
    return (0);
}
