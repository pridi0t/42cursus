/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:04:11 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/12 18:22:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sc;
	int		i;

	dest = (char *)dst;
	sc = (char *)src;
	i = -1;
	if (len == 0 || (dest == 0 && sc == 0))
		return (dst);
	if (dst <= src)
		while (++i < (int)len)
			*(dest + i) = *(sc + i);
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			*(dest + i) = *(sc + i);
			i--;
		}
	}
	return (dst);
}
