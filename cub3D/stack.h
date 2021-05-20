/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 06:48:13 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 17:23:32 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdio.h>
# include <stdlib.h>
# define MAX_STACK_SIZE 1000

typedef struct {
	int		r;
	int		c;
}			t_loc;

typedef	struct {
	t_loc	data[MAX_STACK_SIZE];
	int		top;
}	t_stacktype;

void		init_stack(t_stacktype *s);
int			is_empty(t_stacktype *s);
int			is_full(t_stacktype *s);
void		push(t_stacktype *s, t_loc item);
t_loc		pop(t_stacktype *s);
#endif
