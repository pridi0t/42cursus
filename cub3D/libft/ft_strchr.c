/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:57:22 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/11 22:06:11 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	if (ch != 0)
	{
		while (*(s + i) != 0 && *(s + i) != ch)
			i++;
		if (*(s + i) != 0)
			return ((char *)s + i);
		return (0);
	}
	else
	{
		while (*(s + i) != 0)
			i++;
		return ((char *)s + i);
	}
}
