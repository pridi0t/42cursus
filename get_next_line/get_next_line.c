/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:42:41 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/19 05:21:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static char tmp[10];
    char        buf[BUFFER_SIZE + 1];
    size_t      len;
    size_t      nidx;

    if (fd == -1)
        return (-1);
    while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[len] = 0;
        if (len < BUFFER_SIZE)
        {
            *line = ft_cstrjoin(*line, buf, len);
            tmp[0] = 0;
            return (1);
        }    
        nidx = ft_cstrlen(buf, '\n');
        if (nidx == BUFFER_SIZE - 1)
           *line = ft_cstrjoin(*line, buf, BUFFER_SIZE);
        else
        {
            *line = ft_cstrjoin(*line, buf, (nidx + 1));
            ft_strlcpy(tmp, line[nidx], ft_cstrlen(buf, 0) - (nidx + 1));
            break;
        }
    }
    if(len == -1)
        return (-1);
    else if (len == 0)
        return (0);
    return (1);
}