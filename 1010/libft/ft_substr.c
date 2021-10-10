/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:29:47 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/29 14:39:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*mem;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s + start);
	mem = malloc(len + 1);
	if (mem == 0)
		return (0);
	if (slen >= len)
		ft_strlcpy(mem, (s + start), len + 1);
	else
		ft_strlcpy(mem, (s + start), slen + 1);
	return (mem);
}
