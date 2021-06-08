#include "push_swap.h"

void s(DLList **head, char c)
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
    printf("s%c\n", c);
}

void p(DLList **dst, DLList **src, char c, sinfo *ai, sinfo *bi)
{
    DLList *tmp;

    if (*src == NULL)
        return ;
    tmp = *src;
    insert_first(dst, tmp->data);
    delete_first(src);
    if (c == 'a')
    {
        ai->curele++;
        ai->unsortele++;
        bi->curele--;
    }
    else
    {
        ai->curele--;
        ai->unsortele--;
        bi->curele++;
    }
    printf("p%c\n", c);
}

void r(DLList **head, char c)
{
    if (*head == NULL || *head == (*head)->rlink)
        return ;
    *head = (*head)->rlink;
    printf("r%c\n", c);
}

void rr(DLList **head, char c)
{
    if (*head == NULL || *head == (*head)->rlink)
        return ;
    *head = (*head)->llink;
    printf("rr%c", c);
}