/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:59:24 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 12:30:15 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort_a(t_dllist *s, int cnt)
{
	int i;
	t_dllist *p;

	p = s;
	i = 0;
	while (i < (cnt - 1) && p->data < p->rlink->data)
	{
		p = p->rlink;
		i++;
	}
	if (i == cnt - 1)
		return (1);
	return (0);
}

void	divide_a(t_dllist **a, t_dllist **b, info *info, t_dllist **com)
{
	int i;

	find_pivot(*a, &info->p1, &info->p2, info->cnt);
	i = -1;
	while (++i < info->cnt)
	{
		if ((*a)->data >= info->p2)
		{
			r(a, 'a', com);
			(info->ra_cnt)++;
		}
		else
		{
			p(a, b, 'b', com);
			(info->pb_cnt)++;
			if ((*b)->data >= info->p1)
			{
				r(b, 'b', com);
				(info->rb_cnt)++;
			}
		}
	}
}

void	a_to_b(t_dllist **a, t_dllist **b, int cnt, t_dllist **com)
{
	info info;

	info.ra_cnt = 0;
	info.rb_cnt = 0;
	info.pb_cnt = 0;
	info.cnt = cnt;
	if (info.cnt <= 1)
		return ;
	else if (info.cnt == 2)
	{
		if ((*a)->data > (*a)->rlink->data)
			s(a, 'a', com);
		return ;
	}
	else if (check_sort_a(*a, info.cnt))
		return ;
	divide_a(a, b, &info, com);
	rotation_value(a, b, &info, com);
	a_to_b(a, b, info.ra_cnt, com);
	b_to_a(a, b, info.rb_cnt, com);
	b_to_a(a, b, info.pb_cnt - info.rb_cnt, com);
}
