#include "push_swap.h"

void s(DLList **head)
{
    DLList *tmp;

    if (*head == NULL || *head == (*head)->rlink)
        return ;
    tmp = (*head)->rlink;
    if ((*head)->rlink->rlink == *head)
    {
        (*head)->rlink = *head;
        (*head)->llink = *head; 
    }
    else
        (*head)->rlink = (*head)->rlink->rlink;
    insert_first(head, tmp->data);
    free(tmp);
}

void p(DLList **src, DLList **dst)
{
    DLList *tmp;

    if (*src == NULL)
        return ;
    tmp = *src;
    insert_first(dst, tmp->data);
    delete_first(src);
}

void r(DLList **head)
{
    if (*head == NULL || *head == (*head)->rlink)
        return ;
    *head = (*head)->rlink;
}

void rr(DLList **head)
{
    if (*head == NULL || *head == (*head)->rlink)
        return ;
    *head = (*head)->llink;
}

void rr2(DLList **a, DLList **b)
{
    r(a);
    r(b);
    write(1, "ra", 2);
    write(1, "rb", 2);
}

void rrr2(DLList **a, DLList **b)
{
    rr(a);
    rr(b);
}