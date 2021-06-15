/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:25:05 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 12:37:46 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pivot(t_dllist *head, int *p1, int *p2, int cnt)
{
	t_ddlist	*p;
	int			*arr;
    int			i;

	arr = (int *)malloc(sizeof(int) * cnt);
	i = 0;
	p = head;
	while (i < cnt)
	{
		arr[i] = p->data;
		p = p->rlink;
		i++;
	}
	quick_sort(arr, 0, cnt - 1);
	*p1 = arr[cnt / 3];
	*p2 = arr[(cnt * 2) / 3];
	free(arr);
}

void    rotation_value(t_dllist **a, t_dllist **b, info *info, t_dllist **com)
{
    int i;
    int tmp;

    tmp = info->ra_cnt;
    if (info->ra_cnt > info->rb_cnt)
		tmp = info->rb_cnt;
	i = -1;
	while (++i < tmp)
		rrr2(a, b, com);
	if (info->ra_cnt - tmp > 0)
	{
		i = -1;
		while (++i < info->ra_cnt - tmp)
			rr(a, 'a', com);
        return ;
	}
	else
	{
		i = -1;
		while (++i < info->rb_cnt - tmp)
			rr(b, 'b', com);
	}
}