#include "push_swap.h"
#include "./libft/libft.h"

void insert_a(int argc, char *argv[], DLList **head)
{
    int i;

    i = argc - 1;
    while (i >= 1)
    {
        insert_first(head, ft_atoi(argv[i]));
        i--;
    }
}



void print_arr(int *arr, int size)
{
    int i = 0;

    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void find_pivot(DLList *head, int *p1, int *p2, int cnt)
{
    DLList *p;
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * cnt);
    i = 0;
    p = head;
    while (i < cnt)
    {
        arr[i] = p->data;
        p = p->rlink;
        i++;
    }
    quick_sort(arr, 0, cnt - 1);
    *p1 = arr[cnt / 3];
    *p2 = arr[(cnt * 2) / 3];
    free(arr);
}

void a_to_b(DLList **a, DLList **b, int cnt)
{
    printf("a_to_b(%d)\n", cnt);
    int i;
    int p1, p2;
    int ra_cnt, rb_cnt, pb_cnt;
    int tmp;

    i = 0;
    ra_cnt = 0;
    rb_cnt = 0;
    pb_cnt = 0;
    if (cnt <= 1)
        return ;
    else if (cnt == 2)
    {
        if ((*a)->data > (*a)->rlink->data)
        {
            s(a);
            write(1, "sa\n", 3);
        }
        return ;
    }
    find_pivot(*a, &p1, &p2, cnt);
    while (i < cnt)
    {
        if ((*a)->data >= p2)
        {
            r(a);
            write(1, "ra\n", 3);
            ra_cnt++;
        }
        else
        {
            p(a, b);
            write(1, "pb\n", 3);
            pb_cnt++;
            if ((*b)->data >= p1)
            {
                r(b);
                write(1, "rb\n", 3);
                rb_cnt++;
            }
        }
        i++;
    }
    if (ra_cnt > rb_cnt)
        tmp = rb_cnt;
    else
        tmp = ra_cnt;
    i = 0;
    while (i < tmp)
    {
        rrr2(a, b);
        write(1, "rrr\n", 4);
        i++;
    }
    if (ra_cnt - tmp > 0)
    {
        i = 0;
        while (i < ra_cnt - tmp)
        {
            rr(a);
            write(1, "rra\n", 4);
            i++;
        }
    }
    else if (rb_cnt - tmp > 0)
    {
        i = 0;
        while (i < rb_cnt - tmp)
        {
            rr(b);
            write(1, "rrb\n", 4);
            i++;
        }
    }
    a_to_b(a, b, ra_cnt);
    b_to_a(a, b, rb_cnt);
    b_to_a(a, b, pb_cnt - rb_cnt);
}

void b_to_a(DLList **a, DLList **b, int cnt)
{
    printf("b_to_a(%d)\n", cnt);
    int p1, p2;
    int i;
    int ra_cnt, rb_cnt, pa_cnt;
    int tmp;

    ra_cnt = 0;
    rb_cnt = 0;
    pa_cnt = 0;
    if (cnt <= 0)
        return ;
    else if (cnt == 1)
    {
        p(b, a);
        write(1, "pa\n", 3);
        return ;
    }
    else if (cnt == 2)
    {
        if ((*b)->data < (*b)->rlink->data)
        {
            s(b);
            write(1, "sb\n", 3);
        }
        p(b, a);
        write(1, "pa\n", 3);
        p(b, a);
        write(1, "pa\n", 3);
        return ;
    }
    find_pivot(*b, &p1, &p2, cnt);
    i = 0;
    while (i < cnt)
    {
        if ((*b)->data < p1)
        {
            r(b);
            write(1, "rb\n", 3);
            rb_cnt++;
        }
        else
        {
            p(b, a);
            write(1, "pa\n", 3);
            pa_cnt++;
            if ((*a)->data < p2)
            {
                r(a);
                write(1, "ra\n", 3);
                ra_cnt++;
            }
        }
        i++;
    }
    a_to_b(a, b, pa_cnt - ra_cnt);
    if (ra_cnt > rb_cnt)
        tmp = rb_cnt;
    else
        tmp = ra_cnt;
    i = 0;
    while (i < tmp)
    {
        rrr2(a, b);
        write(1, "rrr\n", 4);
        i++;
    }
    if (ra_cnt - tmp > 0)
    {
        i = 0;
        while (i < ra_cnt - tmp)
        {
            rr(a);
            write(1, "rra\n", 4);
            i++;
        }
    }
    else if (rb_cnt - tmp > 0)
    {
        i = 0;
        while (i < rb_cnt - tmp)
        {
            rr(b);
            write(1, "rrb\n", 4);
            i++;
        }
    }
    a_to_b(a, b, ra_cnt);
    b_to_a(a, b, rb_cnt);
}

int main(int argc, char *argv[])
{
    DLList *a, *b;
    int p1, p2;

    init(&a);
    init(&b);
    if (argc == 1)
        return 0;
    insert_a(argc, argv, &a);

    find_pivot(a, &p1, &p2, argc - 1);
    //print(a, b);
    a_to_b(&a, &b, argc - 1);
    //print(a, b);
    return 0;
}