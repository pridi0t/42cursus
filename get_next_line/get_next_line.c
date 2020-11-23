/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:42:41 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/24 04:33:01 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char tmp[10];
    char        buf[BUFFER_SIZE + 1];
	size_t		len;
	size_t		nlen;

    if (fd == -1)
        return (-1);
	len = ft_cstrlen(tmp, 0);
	nlen = ft_cstrlen(tmp, '\n');
	if (nlen == 0 && len != 0)
	{
		line = ft_strdup("");
		return (1);
	}
	else if (nlen > 0 && len != 0)
	{
		ft_strjoin(line, tmp, nlen);
		ft_strlcpy(tmp, tmp[nlen - 1], nlen);
		return (1);
	}
	strjoin(line, tmp, len);
	tmp[0] = 0;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{

	}
    return (0);
}
