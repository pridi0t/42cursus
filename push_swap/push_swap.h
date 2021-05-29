#include <stdlib.h>
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
void print(DLList *head);
void print2(DLList *a, DLList *b);
// operations
void    s(DLList **head);
void    p(DLList **src, DLList **dst);
void    r(DLList **head);
void    rr(DLList **head);