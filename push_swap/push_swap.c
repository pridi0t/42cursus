#include "push_swap.h"

int main(void)
{
    DLList *a, *b;

    init(&a);
    init(&b);
    insert_first(&a, 1);
    insert_first(&b, 2);
    insert_first(&a, 3);
    insert_first(&b, 4);
    return 0;
}