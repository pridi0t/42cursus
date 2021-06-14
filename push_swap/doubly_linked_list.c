/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:10 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 06:25:57 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(DLList **head)
{
	*head = NULL;
}

void	insert_first(DLList **head, int data)
{
	DLList *new;

	new = (DLList *)malloc(sizeof(DLList));
	new->data = data;
	if (*head == NULL)
	{
		*head = new;
		new->llink = new;
		new->rlink = new;
	}
	else
	{
		(*head)->llink->rlink = new;
		new->llink = (*head)->llink;
		new->rlink = *head;
		(*head)->llink = new;
		*head = new;
	}
}

void	insert_last(DLList **head, int data)
{
	DLList *new;

	new = (DLList *)malloc(sizeof(DLList));
	new->data = data;
	if (*head == NULL)
	{
		*head = new;
		new->llink = new;
		new->rlink = new;
	}
	else
	{
		(*head)->llink->rlink = new;
		new->llink = (*head)->llink;
		new->rlink = *head;
		(*head)->llink = new;
	}
}

void	delete_first(DLList **head)
{
	DLList *tmp;

	if (*head == NULL)
		return ;
	else if (*head == (*head)->rlink)
	{
		free(*head);
		*head = 0;
	}
	else
	{
		tmp = *head;
		(*head)->rlink->llink = (*head)->llink;
		(*head)->llink->rlink = (*head)->rlink;
		*head = (*head)->rlink;
		free(tmp);
	}
}

void	print(DLList *a, DLList *b)
{
	DLList *p;

	p = a;
	if (p == 0)
		return ;
	printf("<-| %d |->", p->data);
	p = p->rlink;
	while (p != a)
	{
		printf("<-| %d |->", p->data);
		p = p->rlink;
	}
	printf("\n");
	p = b;
	if (p == 0)
		return ;
	printf("<-| %d |->", p->data);
	p = p->rlink;
	while (p != b)
	{
		printf("<-| %d |->", p->data);
		p = p->rlink;
	}
	printf("\n");
}
