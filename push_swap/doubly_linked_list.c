/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:10 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 13:19:19 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_dllist **head)
{
	*head = NULL;
}

void	insert_first(t_dllist **head, int data)
{
	t_dllist *new;

	new = (t_dllist *)malloc(sizeof(t_dllist));
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

void	insert_last(t_dllist **head, int data)
{
	t_dllist *new;

	new = (t_dllist *)malloc(sizeof(t_dllist));
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

void	delete_first(t_dllist **head)
{
	t_dllist *tmp;

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
