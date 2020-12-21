/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:25:31 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/21 13:28:35 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cb;

	cb = b;
	i = 0;
	while (i < len)
	{
		*(cb + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
