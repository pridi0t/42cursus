/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 06:07:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/16 06:52:56 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_stack(t_stacktype *s)
{
	s->top = -1;
}

int		is_empty(t_stacktype *s)
{
	return (s->top == -1);
}

int		is_full(t_stacktype *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void	push(t_stacktype *s, element item)
{
	if (is_full(s))
	{
		printf("Error\nStack full error\n");
		exit(1);
	}
	s->data[++(s->top)] = item;
}

element	pop(t_stacktype *s)
{
	if (is_empty(s))
	{
		printf("Error\nStack empty error\n");
		exit(1);
	}
	return (s->data[(s->top)--]);
}
