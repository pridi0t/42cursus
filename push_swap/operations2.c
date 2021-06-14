/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:34:54 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 07:10:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    optimization_command(DLList **com)
{
    DLList *p;

    p = *com;
    *com = (*com)->rlink;
    while (*com != p)
    {
        if (((*com)->data == SA && (*com)->llink->data == SB) || ((*com)->data == SB && (*com)->llink->data == SA))
        {
            *com = (*com)->llink;
            delete_first(com);
            delete_first(com);
            insert_first(com, SS);
        }
        else if (((*com)->data == RA && (*com)->llink->data == RB) || ((*com)->data == RB && (*com)->llink->data == RA))
        {
            *com = (*com)->llink;
            delete_first(com);
            delete_first(com);
            insert_first(com, RR);
        }
        else if (((*com)->data == RRA && (*com)->llink->data == RRB) || ((*com)->data == RRB && (*com)->llink->data == RRA))
        {
            *com = (*com)->llink;
            delete_first(com);
            delete_first(com);
            insert_first(com, RRR);
        }
        *com = (*com)->rlink;
    }
}

void print_command(DLList **com)
{
    while (*com != NULL)
    {
        if ((*com)->data == SS)
            write(1, "ss\n", 3);
        else if ((*com)->data == SA)
            write(1, "sa\n", 3);
        else if ((*com)->data == SB)
            write(1, "sb\n", 3);
        else if ((*com)->data == PA)
            write(1, "pa\n", 3);
        else if ((*com)->data == PB)
            write(1, "pb\n", 3);
        else if ((*com)->data == RR)
            write(1, "rr\n", 3);
        else if ((*com)->data == RA)
            write(1, "ra\n", 3);
        else if ((*com)->data == RB)
            write(1, "rb\n", 3);
        else if ((*com)->data == RRR)
            write(1, "rrr\n", 4);
        else if ((*com)->data == RRA)
            write(1, "rra\n", 4);
        else if ((*com)->data == RRB)
            write(1, "rrb\n", 4);
        //print(*com, 0);
        delete_first(com);
    }
}