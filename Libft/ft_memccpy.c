/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:49:29 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/09 18:34:12 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	src2 = (char *)src;
	while (*(src2 + i) != c && *(src2 + i) != 0)
		i++;
	i++;
	if (i <= n)
	{
		dst2 = (char *)ft_memcpy(dst, src, i);
		return (dst2 + i);
	}
	else
	{
		dst2 = (char *)ft_memcpy(dst, src, n);
		return (0);
	}
}
