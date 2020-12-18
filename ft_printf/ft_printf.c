/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:25:47 by hyojang           #+#    #+#             */
/*   Updated: 2020/12/18 18:01:52 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		create_str(char *str[], int *i)
{
	char *p;

	p = calloc(10, sizeof(char));
	if (p == 0)
		return (-1);
	while (str[*i] != )


}

void	set_format(t_format *t, char *str[], int *i)
{
	if (str[*i] == '-' || str[*i] == '0' || str[*i] == '*')
	{
		t->flag = str[*i];
		(*i)++;
	}



}

int		ft_printf(const char *str, ...)
{
	t_format	t;
	va_list		p;
	int			i;
	int			read;

	i = 0;
	read = 0;
	va_start(p, str);
	while (str[i] != 0 && p != 0)
	{
		if (str[i] == '%' && read == 0)
			read = 1;
		else if (args[i] == '%' && read == 1)
			set_format(&t, &str, &(++i));
		else
			write(1, &args[i], 1);
		i++;
	}
	return (0);
}
