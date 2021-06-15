/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exception.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:03:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 12:26:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exception_arg(char ***str, int *cnt, int argc, char *argv[])
{
	if (argc == 1)
		exit(1);
	else if (argc == 2)
	{
		*str = ft_split(argv[1], ' ');
		*cnt = 0;
		while (*(*str + *cnt) != 0)
			(*cnt)++;
		if (*cnt == 1)
		{
			if (check_int(*str[0]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
	}
	else
	{
		*cnt = argc - 1;
		*str = &argv[1];
	}
}

int		exception_cnt(int cnt, t_dllist **a, t_dllist **b, t_dllist **com)
{
	if (cnt == 3)
	{
		sort3_a(a, com);
		print_command2(com);
		return (0);
	}
	else if (cnt == 5)
	{
		sort5_a(a, b, 5, com);
		print_command2(com);
		return (0);
	}
	else
	{
		a_to_b(a, b, cnt, com);
		print_command2(com);
		return (0);
	}
}
