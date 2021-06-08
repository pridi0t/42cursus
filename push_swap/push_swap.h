#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int curele;
    int sortele;
    int unsortele;
} sinfo;

typedef struct DLList{
    int data;
    struct DLList *llink;
    struct DLList *rlink;
} DLList;

// linked_list
void    init(DLList **head);
void    insert_first(DLList **head, int data);
void    delete_first(DLList **head);
void print(DLList *a, DLList *b, sinfo *ai, sinfo *bi);
// operations
void    s(DLList **head, char c);
void    p(DLList **dst, DLList **src, char c, sinfo *ai, sinfo *bi);
void    r(DLList **head, char c);
void    rr(DLList **head, char c);