/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:13:57 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/24 02:05:54 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

int     get_next_line(int fd, char **line);
size_t  ft_cstrlen(char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_cstrjoin(char const *s1, char const *s2, size_t s2Size);
char	*ft_strdup(const char *s1);
#endif
