/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:24:42 by hyojang           #+#    #+#             */
/*   Updated: 2020/10/21 16:26:05 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mem;

	i = 0;
	mem = ft_strdup(s);
	if (mem == 0)
		return (0);
	while (*(mem + i) != 0)
	{
		*(mem + i) = f(i, *(s + i));
		i++;
	}
	return (mem);
}
