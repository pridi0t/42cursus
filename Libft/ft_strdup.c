/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:26:49 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/18 17:03:48 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*mem;

	i = 0;
	len = ft_strlen(s1);
	if (len == 0)
	{
		mem = (char *)malloc(10);
		return (mem);
	}
	mem = (char *)malloc(len + (len / 2));
	if (mem == 0)
		return (0);
	mem = (char *)ft_memcpy(mem, s1, len);
	*(mem + i) = 0;
	return (mem);
}
