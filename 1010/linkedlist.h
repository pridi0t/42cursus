/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:26:07 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 15:48:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct s_listnode {
	char				*key;
	char				*val;
	struct s_listnode	*link;
}	t_listnode;

t_listnode	*insert_first(t_listnode *head, char *key, char *val);
t_listnode	*insert_last(t_listnode *head, char *key, char *val);
t_listnode	*delete_first(t_listnode *head);
t_listnode	*delete(t_listnode *head, t_listnode *pre);
t_listnode	*delete_last(t_listnode *head);
t_listnode	*search(t_listnode *head, char *key, t_listnode **ret);
t_listnode	*swap_val(t_listnode *head, char *key1, char *key2);
t_listnode	*change_val(t_listnode *head, char *key, char *val);
int			get_nlen(t_listnode *node);
#endif
