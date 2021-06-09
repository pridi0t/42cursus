#include <stdlib.h>
#include <unistd.h>
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
// main
void    a_to_b(DLList **a, DLList **b, int cnt);
void    b_to_a(DLList **a, DLList **b, int cnt);