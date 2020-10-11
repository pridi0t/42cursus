/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:50:56 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/11 23:14:19 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	while (*(s + i) != 0)
		i++;
	if (ch != 0)
	{
		while (i > 0 && *(s + i) != ch)
			i--;
		if (i != 0)
			return ((char *)s + i);
		return (0);
	}
	else
		return ((char *)s + i);
}
