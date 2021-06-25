/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:52:16 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/18 23:08:39 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (mem);
}
