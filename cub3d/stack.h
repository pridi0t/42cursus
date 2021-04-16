/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 06:48:13 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/16 09:41:27 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct{
	int r;
	int c;
}		element;

typedef	struct {
	element	data[MAX_STACK_SIZE];
	int		top;
}		t_stacktype;

void	init_stack(t_stacktype *s);
int		is_empty(t_stacktype *s);
int		is_full(t_stacktype *s);
void	push(t_stacktype *s, element item);
element	pop(t_stacktype *s);
