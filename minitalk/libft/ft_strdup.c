/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:26:49 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/18 22:21:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mem;

	len = ft_strlen(s1);
	mem = (char *)malloc(len + 1);
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1, len + 1);
	return (mem);
}
