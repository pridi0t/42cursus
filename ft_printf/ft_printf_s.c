/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:53:11 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/27 20:51:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_flag_s(t_format *t, int *lsort)
{
	if (t->flag2 != 0)
		return (-1);
	if (t->flag1 == '0' || t->flag1 == '*')
		return (-1);
	else if (t->flag == '-')
		*lsort = 1;
	return (0);
}

int	print_s(t_format *t, t_status *s, va_list p)
{
	char	*str;
	int		slen;
	int		i;
	int		lsort;
	
	i = 0;
	lsort = 0;
	s->result = 0 ;
	str = va_arg(p, char *);
	slen = ft_strlen(str);
	if (check_flag_s(t, *lsort) == -1)
		return (-1);
	if (t->width != -1 && t->dot != 0 && t->precision != -1)
	{
		if (t->width < slen)
		{
			while (i < t->width)
			{
				write(1, &str[i], 1);
				(s->result)++;
				i++;
			}
		}
		else
		{
			if (t->width < t->precision)
			{
				while(str[i] != 0)
				{
					write(1, &str[i], 1);
					i++;
				}
			}
			else if (t->width > t->precision)
			{
				while (i < t->precision)
				{
					if (i < (t->width - t->precision) && t->flag1 != '-')
						write(1, " ", 1);
					else if (i < (t->width - t->precision) && t->flag1 == '-')
						write(1, &str[i], 1);
					else if (i >= (t->width - t->precision) && t->flag1 != '-')
						write(1, &str[i], 1);
					else
						write(1, " ", 1);
					i++;
				}
			}
			else
			{
				if (t->width < slen)
				{
					while (i < t->width)
					{
						write(1, &str[i], 1);
						i++;
					}
				}
				else
				{
					while (i < t->width)
					{
						if (i < (t->width - slen))
							write(1, " ", 1);
						else
							write(1, &str[i], 1);
						i++;
					}
				}
			}
		}
	}
	return (0);
}
