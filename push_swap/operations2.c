/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:34:54 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/12 22:24:07 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_command(DLList **head)
{
    head = head->llink;
    while (head != NULL)
    {
        if (((*head)->data == SA && (*head)->llink->data == SB) || ((*head)->data == SB && (*head)->llink->data == SA))
        {
            write(1, "ss\n", 3);
            delete_first(head);
        }
        else if (((*head)->data == RA && (*head)->llink->data == RB) || ((*head)->data == RB && (*head)->llink->data == RA))
        {
            write(1, "rr\n", 3);
            delete_first(head);
        }
        else if (((*head)->data == RRA && (*head)->llink->data == RRB) || ((*head)->data == RRB && (*head)->llink->data == RRA))
        {
            write(1, "rrr\n", 3);
            delete_first(head);
        }
        else if ((*head)->data == SS)
            write(1, "ss\n", 3);
        else if ((*head)->data == SA)
            write(1, "sa\n", 3);
        else if ((*head)->data == SB)
            write(1, "sb\n", 3);
        else if ((*head)->data == PA)
            write(1, "pa\n", 3);
        else if ((*head)->data == PB)
            write(1, "pb\n", 3);
        else if ((*head)->data == RR)
            write(1, "rr\n", 3);
        else if ((*head)->data == RA)
            write(1, "ra\n", 3);
        else if ((*head)->data == RB)
            write(1, "rb\n", 3);
        else if ((*head)->data == RRR)
            write(1, "rrr\n", 4);
        else if ((*head)->data == RRA)
            write(1, "rra\n", 4);
        else if ((*head)->data == RRB)
            write(1, "rrb\n", 4);
        delete_first(head);
        head = head->llink;
    }
}