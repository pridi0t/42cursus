/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 07:34:30 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/12 20:51:04 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include <stdio.h>

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