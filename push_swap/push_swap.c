/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:01:05 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 13:51:56 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_a(int argc, char *argv[], t_dllist **head)
{
	int i;

	i = argc - 1;
	while (i >= 0)
	{
		insert_first(head, ft_atoi(argv[i]));
		i--;
	}
}

int		main(int argc, char *argv[])
{
	t_dllist	*a;
	t_dllist	*b;
	t_dllist	*com;
	char		**str;
	int			cnt;

	init(&a);
	init(&b);
	init(&com);
	str = 0;
	exception_arg(&str, &cnt, argc, argv);
	if (check_input(cnt, str))
		return (0);
	insert_a(cnt, str, &a);
	exception_cnt(cnt, &a, &b, &com);
	return (0);
}
