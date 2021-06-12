/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:23:57 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/12 21:23:31 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort3_a(DLList **a)
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
        r(a);
        write(1, "ra\n", 3);
        if (n2 > n3)
        {
            s(a);
            write(1, "sa\n", 3);
        }
    }
    else if (n2 > n1 && n2 > n3)
    {
        rr(a);
        write(1, "rra\n", 4);
        if (n1 < n2)
        {
            s(a);
            write(1, "sa\n", 3);
        }
    }
    else
    {
        s(a);
        write(1, "sa\n", 3);
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

void sort5_a(DLList **a, DLList **b, int cnt)
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
        {
            r(a);
            write(1, "ra\n", 3);
        }
        else
        {
            p(a, b);
            write(1, "pb\n", 3);
        }
    }
    sort3_a(a);
    if ((*b)->data < (*b)->rlink->data)
    {
        s(b);
        write(1, "sb\n", 3);
    }
    p(b, a);
    write(1, "pa\n", 3);
    p(b, a);
    write(1, "pa\n", 3);
}