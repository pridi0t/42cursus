/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:19:10 by hyojang           #+#    #+#             */
/*   Updated: 2021/01/13 16:37:23 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prtc(int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

int			result_p(t_format *t, char *str)
{
	int i;

	i = 0;
	if (t->width > ((int)ft_strlen(str) + 2))
	{
		if (t->flag == '-')
		{
			write(1, "0x", 2);
			write(1, str, ft_strlen(str));
		}
		if (t->flag == '0')
			prtc(t->width - ft_strlen(str) - 2, '0');
		else
			prtc(t->width - ft_strlen(str) - 2, ' ');
		if (t->flag != '-')
		{
			write(1, "0x", 2);
			write(1, str, ft_strlen(str));
		}
		return (t->width);
	}
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str) + 2);
}

int			print_p(t_format *t, va_list p)
{
	int		result;
	char	*str;

	str = va_arg(p, char *);
	str = ft_ltox((long long)str);
	result = result_p(t, str);
	free(str);
	return (result);
}
