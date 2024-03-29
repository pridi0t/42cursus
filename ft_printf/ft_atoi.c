/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:30:30 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/21 13:21:31 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'	\
			|| c == '\r' || c == ' ')
		return (1);
	else if (c == '+' || c == '-')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

int	r_check(unsigned long long n, int sign)
{
	if (n > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	else
		return (sign * n);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					sign;

	i = 0;
	sign = 1;
	result = 0;
	while (*(str + i) != 0 && check(*(str + i)) == 1)
		i++;
	if (check(*(str + i)) == 2)
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) != 0 && check(*(str + i)) == 3)
	{
		result = (result * 10) + (*(str + i) - '0');
		i++;
	}
	if (i == 0)
		return (0);
	if (check(*(str + --i)) == 3)
		return (r_check(result, sign));
	return (0);
}
