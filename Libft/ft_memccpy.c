/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:49:29 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/09 17:26:06 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst2;

	i = 0;
	while (*(src2 + i) != c && *(src2 + i) != 0)
		i++;
	if (i != 0)
	{
		dst2 = (char *)ft_memcpy(dst, src, n) + 1;
		return (dst2);
	}
	else
		return (0);
}
