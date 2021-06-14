/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 08:59:24 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 07:45:24 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pivot(DLList *head, int *p1, int *p2, int cnt)
{
	DLList	*p;
	int		*arr;
    int		i;

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

void    rotation_value(DLList **a, DLList **b, int ra_cnt, int rb_cnt, DLList **com)
{
    int i;
    int tmp;

	//printf("ra : %d, rb : %d\n", ra_cnt, rb_cnt);
    tmp = ra_cnt;
    if (ra_cnt > rb_cnt)
		tmp = rb_cnt;
	i = -1;
	while (++i < tmp)
		rrr2(a, b, com);
	if (ra_cnt - tmp > 0)
	{
		i = -1;
		while (++i < ra_cnt - tmp)
			rr(a, 'a', com);
        return ;
	}
	else
	{
		i = -1;
		while (++i < rb_cnt - tmp)
			rr(b, 'b', com);
	}
}

int		check_sort_a(DLList *s, int cnt)
{
	int i;
	DLList *p;
	
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

void	a_to_b(DLList **a, DLList **b, int cnt, DLList **com)
{
	//printf("a_to_b(%d)\n", cnt);
	int i;
	int p1, p2;
	int ra_cnt, rb_cnt, pb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	if (cnt <= 1)
		return ;
	else if (cnt == 2)
	{
		if ((*a)->data > (*a)->rlink->data)
			s(a, 'a', com);
		return ;
	}
	else if (check_sort_a(*a, cnt))
		return ;
	find_pivot(*a, &p1, &p2, cnt);
	i = 0;
	while (i < cnt)
	{
		if ((*a)->data >= p2)
		{
			r(a, 'a', com);
			ra_cnt++;
		}
		else
		{
			p(a, b, 'b', com);
			pb_cnt++;
			if ((*b)->data >= p1)
			{
				r(b, 'b', com);
				rb_cnt++;
			}
		}
		//printf("\n");
		//print(*a, *b);
		//printf("\n");
		i++;
	}
	rotation_value(a, b, ra_cnt, rb_cnt, com);
	a_to_b(a, b, ra_cnt, com);
	b_to_a(a, b, rb_cnt, com);
	b_to_a(a, b, pb_cnt - rb_cnt, com);
}

void	b_to_a(DLList **a, DLList **b, int cnt, DLList **com)
{
	//printf("b_to_a(%d)\n", cnt);
	int p1, p2;
	int i;
	int ra_cnt, rb_cnt, pa_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	if (cnt <= 0)
		return ;
	else if (cnt == 1)
	{
		p(b, a, 'a', com);
		return ;
	}
	else if (cnt == 2)
	{
		if ((*b)->data < (*b)->rlink->data)
			s(b, 'b', com);
		p(b, a, 'a', com);
		p(b, a, 'a', com);
		return ;
	}
	find_pivot(*b, &p1, &p2, cnt);
	i = 0;
	while (i < cnt)
	{
		if ((*b)->data < p1)
		{
			r(b, 'b', com);
			rb_cnt++;
		}
		else
		{
			p(b, a, 'a', com);
			pa_cnt++;
			if ((*a)->data < p2)
			{
				r(a, 'a', com);
				ra_cnt++;
			}
		}
		i++;
	}
	a_to_b(a, b, pa_cnt - ra_cnt, com);
	rotation_value(a, b, ra_cnt, rb_cnt, com);
	a_to_b(a, b, ra_cnt, com);
	b_to_a(a, b, rb_cnt, com);
}