/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:23:57 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 05:36:05 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort3_a(DLList **a, DLList **com)
{
    //printf("strt3_a\n");
    int n1;
    int n2;
    int n3;

    if (check_sort_a(*a, 3))
        return ;
    n1 = (*a)->data;
    n2 = (*a)->rlink->data;
    n3 = (*a)->rlink->rlink->data;
    
    if (n1 > n2 && n1 > n3)
    {
        r(a, 'a', com);
        if (n2 > n3)
            s(a, 'a', com);
    }
    else if (n3 > n1 && n3 > n2)
        s(a, 'a', com);
    else
    {
        rr(a, 'a', com);
        if (n1 < n2 && n1 < n3)
            s(a, 'a', com);
    }
}

void    find_pivot1(DLList *head, int *pivot, int cnt)
{
    DLList  *p;
    int     *arr;
    int     i;

    arr = (int *)malloc(sizeof(int) * cnt);
    i = -1;
    p = head;
    while (++i < cnt)
    {
        arr[i] = p->data;
        p = p->rlink;
    }
    quick_sort(arr, 0, cnt - 1);
    *pivot = arr[(cnt / 2)];
    free(arr);
}

void    sort5_a(DLList **a, DLList **b, int cnt, DLList **com)
{
    //printf("sort5_a\n");
    int i;
    int pivot;

    find_pivot1(*a, &pivot, cnt);
    //printf("pivot : %d", pivot);
    i = -1;
    while (++i < cnt)
    {
        if ((*a)->data >= pivot)
            r(a, 'a', com);
        else
            p(a, b, 'b', com);
    }
    sort3_a(a, com);
    if ((*b)->data < (*b)->rlink->data)
        s(b, 'b', com);
    p(b, a, 'a', com);
    p(b, a, 'a', com);
}