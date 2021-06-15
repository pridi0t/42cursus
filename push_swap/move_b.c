/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:28:57 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 12:27:48 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_b(t_dllist **a, t_dllist **b, info *info, t_dllist **com)
{
    int i;
    
    find_pivot(*b, &info->p1, &info->p2, info->cnt);
	i = -1;
	while (++i < info->cnt)
	{
		if ((*b)->data < info->p1)
		{
			r(b, 'b', com);
			(info->rb_cnt)++;
		}
		else
		{
			p(b, a, 'a', com);
			(info->pa_cnt)++;
			if ((*a)->data < info->p2)
			{
				r(a, 'a', com);
				(info->ra_cnt)++;
			}
		}
	}
}

void	b_to_a(t_dllist **a, t_dllist **b, int cnt, t_dllist **com)
{
    info info;

	info.ra_cnt = 0;
	info.rb_cnt = 0;
	info.pa_cnt = 0;
    info.cnt = cnt;
	if (info.cnt <= 0)
		return ;
	else if (info.cnt == 1)
	{
		p(b, a, 'a', com);
		return ;
	}
	else if (info.cnt == 2)
	{
		if ((*b)->data < (*b)->rlink->data)
			s(b, 'b', com);
		p(b, a, 'a', com);
		p(b, a, 'a', com);
		return ;
	}
	divide_b(a, b, &info, com);
	a_to_b(a, b, info.pa_cnt - info.ra_cnt, com);
	rotation_value(a, b, &info, com);
	a_to_b(a, b, info.ra_cnt, com);
	b_to_a(a, b, info.rb_cnt, com);
}
