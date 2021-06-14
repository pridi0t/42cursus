/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:30 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 04:06:20 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include <stdio.h>

#define SS 0
#define SA 1
#define SB 2
#define PA 3
#define PB 4
#define RR 5
#define RA 6
#define RB 7
#define RRR 8
#define RRA 9
#define RRB 10

typedef struct DLList{
	int data;
	struct DLList *llink;
	struct DLList *rlink;
} DLList;

// linked_list
void    init(DLList **head);
void    insert_first(DLList **head, int data);
void	insert_last(DLList **head, int data);
void	delete_first(DLList **head);
void print(DLList *a, DLList *b);
// Quick_Sort
void    quick_sort(int *arr, int start, int end);
// operations1
void	s(DLList **head, char c, DLList **com);
void	p(DLList **src, DLList **dst, char dc, DLList **com);
void	r(DLList **head, char c, DLList **com);
void	rr(DLList **head, char c, DLList **com);
void	rr2(DLList **a, DLList **b, DLList **com);
void	rrr2(DLList **a, DLList **b, DLList **com);
// operations2
void optimization_command(DLList **com);
void	print_command(DLList **com);
// move
void	find_pivot(DLList *head, int *p1, int *p2, int cnt);
int		check_sort_a(DLList *s, int cnt);
void	a_to_b(DLList **a, DLList **b, int cnt, DLList **com);
void	b_to_a(DLList **a, DLList **b, int cnt, DLList **com);
// sort3
void    sort3_a(DLList **a, DLList **com);
void	sort5_a(DLList **a, DLList **b, int cnt, DLList **com);