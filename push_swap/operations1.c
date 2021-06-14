/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:18 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 07:54:24 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(DLList **head, char c, DLList **com)
{
	DLList *tmp;

	if (*head == NULL || *head == (*head)->rlink)
		return ;
	tmp = (*head)->rlink;
	if ((*head)->rlink->rlink == *head)
	{
		(*head)->rlink = *head;
		(*head)->llink = *head;
	}
	else
		(*head)->rlink = (*head)->rlink->rlink;
	insert_first(head, tmp->data);
	free(tmp);
	if (c == 'a')
		insert_last(com, SA);
	else
		insert_last(com, SB);
}

void	p(DLList **src, DLList **dst, char dc, DLList **com)
{
	DLList *tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	insert_first(dst, tmp->data);
	delete_first(src);
	if (dc == 'a')
		insert_last(com, PA);
	else
		insert_last(com, PB);
}

void	r(DLList **head, char c, DLList **com)
{
	if (*head == NULL)
		return ;
	*head = (*head)->rlink;
	if (c == 'a')
		insert_last(com, RA);
	else
		insert_last(com, RB);
}

void	rr(DLList **head, char c, DLList **com)
{
	if (*head == NULL)
		return ;
	*head = (*head)->llink;
	if (c == 'a')
		insert_last(com, RRA);
	else
		insert_last(com, RRB);
}

void	rrr2(DLList **a, DLList **b, DLList **com)
{
	if (*a != NULL)
		*a = (*a)->llink;
	if (*b != NULL)
		*b = (*b)->llink;
	insert_last(com, RRR);
}
