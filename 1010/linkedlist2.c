/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:19:54 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/06 15:48:16 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_listnode	*search(t_listnode *head, char *key, t_listnode **ret)
{
	t_listnode	*p;
	t_listnode	*pre;
	int			strlen;

	strlen = ft_strlen(key);
	p = head;
	pre = NULL;
	while (p != NULL)
	{
		if (ft_strncmp(p->key, key, (ft_strlen(key) + 1)) == 0)
			return (p);
		pre = p;
		p = p->link;
	}
	if (ret != 0)
		*ret = pre;
	return (NULL);
}

t_listnode	*swap_val(t_listnode *head, char *key1, char *key2)
{
	t_listnode	*node1;
	t_listnode	*node2;
	char		*tmp;

	node1 = search(head, key1, NULL);
	node2 = search(head, key2, NULL);
	if (node1 != NULL && node2 != NULL)
	{
		tmp = node1->val;
		node1->val = node2->val;
		node2->val = tmp;
	}
	return (head);
}

t_listnode	*change_val(t_listnode *head, char *key, char *val)
{
	t_listnode	*p;

	p = search(head, key, NULL);
	if (p != NULL)
	{
		if (p->val != NULL)
			free(p->val);
		p->val = ft_strdup(val);
	}
	return (head);
}

int	get_nlen(t_listnode *node)
{
	t_listnode	*p;
	int			len;

	p = node;
	len = 0;
	while (p != 0)
	{
		p = p->link;
		len++;
	}
	return (len);
}
