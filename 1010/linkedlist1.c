/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:00:54 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/03 18:23:00 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_listnode	*insert_first(t_listnode *head, char *key, char *val)
{
	t_listnode	*p;

	p = (t_listnode *)malloc(sizeof(t_listnode));
	p->key = key;
	p->val = val;
	p->link = head;
	head = p;
	return (head);
}

t_listnode	*insert_last(t_listnode *head, char *key, char *val)
{
	t_listnode	*new;
	t_listnode	*p;

	p = head;
	new = (t_listnode *)malloc(sizeof(t_listnode));
	new->key = key;
	new->val = val;
	new->link = 0;
	if (p == 0)
		head = new;
	else
	{
		while (p->link != 0)
			p = p->link;
		p->link = new;
	}
	return (head);
}

t_listnode	*delete_first(t_listnode *head)
{
	t_listnode	*removed;

	if (head == NULL)
		return (NULL);
	removed = head;
	head = removed->link;
	free(removed->key);
	free(removed->val);
	removed->key = NULL;
	removed->val = NULL;
	removed->link = NULL;
	free(removed);
	return (head);
}

t_listnode	*delete(t_listnode *head, t_listnode *pre)
{
	t_listnode	*removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed->key);
	free(removed->val);
	removed->key = NULL;
	removed->val = NULL;
	removed->link = NULL;
	free(removed);
	return (head);
}

t_listnode	*delete_last(t_listnode *head)
{
	t_listnode	*pre;

	if (head == NULL)
		return (NULL);
	else if (head->link == NULL)
		return (delete_first(head));
	pre = head;
	while ((pre->link)->link != NULL)
		pre = pre->link;
	return (delete(head, pre));
}
