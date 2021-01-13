/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:25:31 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 15:46:30 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		catoi(char *str, int *i)
{
	char	s[20];
	int		j;

	j = 0;
	ft_memset(s, 0, sizeof(s));
	while (ft_isdigit(str[*i]) != 0)
	{
		s[j] = str[*i];
		(*i)++;
		j++;
	}
	if (j == 0)
		return (-1);
	return (ft_atoi(s));
}

int		isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
