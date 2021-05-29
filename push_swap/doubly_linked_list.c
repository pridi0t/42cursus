#include "push_swap.h"

void init(DLList **head)
{
    *head = NULL;
}

void insert_first(DLList **head, int data)
{
    DLList *new = (DLList *)malloc(sizeof(DLList));
    new->data = data;
    if (*head == NULL)
    {
        *head = new;
        new->llink = new;
        new->rlink = new;
    }
    else
    {
        (*head)->llink->rlink = new;
        new->llink = (*head)->llink;
        new->rlink = *head;
        (*head)->llink = new;
        *head = new;
    }
}

void delete_first(DLList **head)
{
    DLList *tmp;

    if (*head == NULL)
        return ;
    else if (*head == (*head)->rlink)
    {
        free(*head);
        *head = 0;
    }
    else
    {
        tmp = *head;
        (*head)->rlink->llink = (*head)->llink;
        (*head)->llink->rlink = (*head)->rlink;
        *head = (*head)->rlink;
        free(tmp);
    }
}

void print(DLList *head)
{
    DLList *p = head;
    
    if (p == 0)
        return ;
    printf("<-| %d |->", p->data);
    p = p->rlink;
    while (p != head)
    {
        printf("<-| %d |->", p->data);
        p = p->rlink;
    }
    printf("\n");
}