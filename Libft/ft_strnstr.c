/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:30:33 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/17 00:41:01 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hlen;
	size_t	nlen;
	size_t	i;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	i = 0;
	if (nlen == 0)
		return ((char *)haystack);
	if (len == 0 || hlen == 0)
		return (0);
	while (i < (len - nlen) && *(haystack + i) != 0)
	{
		if (ft_memcmp((haystack + i), needle, nlen) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
