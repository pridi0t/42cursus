/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:13:57 by hyojang           #+#    #+#             */
/*   Updated: 2020/11/23 18:01:03 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

int     get_next_line(int fd, char **line);
size_t  ft_cstrlen(char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	len_check(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_cstrjoin(char const *s1, char const *s2, size_t s2Size);
#endif
