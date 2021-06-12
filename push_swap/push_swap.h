/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:30 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/12 22:00:45 by hyojang          ###   ########.fr       */
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
void    delete_first(DLList **head);
void print(DLList *a, DLList *b);
// Quick_Sort
void    quick_sort(int *arr, int start, int end);
// operations
void    s(DLList **head);
void    p(DLList **src, DLList **dst);
void    r(DLList **head);
void    rr(DLList **head);
void    rr2(DLList **a, DLList **b);
void    rrr2(DLList **a, DLList **b);
// move
void	find_pivot(DLList *head, int *p1, int *p2, int cnt);
int		check_sort_a(DLList *s, int cnt);
void    a_to_b(DLList **a, DLList **b, int cnt);
void    b_to_a(DLList **a, DLList **b, int cnt);
// sort3
void    sort3_a(DLList **a);
void	sort5_a(DLList **a, DLList **b, int cnt);