#include "push_swap.h"
#include "./libft/libft.h"

void init_sinfo(sinfo *sinfo, int element)
{
    sinfo->curele = element;
    sinfo->sortele = 0;
    sinfo->unsortele = sinfo->curele;
}

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

void find_value(int *max, int *min, DLList *head, int cnt)
{
    DLList *dp;
    int num;

    dp = head;
    num = 0;
    if (head == NULL || dp == dp->rlink)
        return ;
    *max = head->data;
    *min = head->data;
    dp = dp->rlink;
    while (dp != head, num < cnt)
    {
        if (*max < dp->data)
            *max = dp->data;
        if (*min > dp->data)
            *min = dp->data;
        dp = dp->rlink;
        num++;
    }
}

int check_sort(DLList *a, int elenum, int mod)
{
    DLList *dp;
    int i;

    dp = a;
    i = 1;
    if (mod == 1)
    {
        while (dp->data < dp->rlink->data && dp->rlink != a)
        {
            dp = dp->rlink;
            i++;
        }
        if (i == elenum)
            return 1;
        return 0;
    }
    while (dp->data > dp->rlink->data && dp->rlink != a)
    {
        dp = dp->rlink;
        i++;
    }
    if (i == elenum)
        return 1;
    return 0;
}

void sorted_insert_a(DLList **a, sinfo *ai)
{
    int cnt;

    cnt = 0;
    if (check_sort(*a, ai->unsortele, 1))
    {
        if (ai->sortele > 0)
        {
            while (cnt < ai->unsortele)
            {
                r(a, 'a');
                cnt++;
            }
        }
        ai->sortele += ai->unsortele;
        ai->unsortele = 0;
    }
}

void sorted_insert_b(DLList **a, DLList **b, sinfo *ai, sinfo *bi)
{
    int cnt;
    int swapnum;

    cnt = 0;
    swapnum = bi->curele;
    if (check_sort(*b, bi->curele, 2) && ai->unsortele == 0)
    {
        while (cnt < swapnum)
        {
            p(a, b, 'a', ai, bi);
            cnt++;
        }
        cnt = 0;
        while (cnt < swapnum)
        {
            r(a, 'a');
            cnt++;
        }
        ai->sortele += swapnum;
        ai->curele += swapnum;
        bi->curele -= swapnum;
    }
}

void divide_a(DLList **a, DLList **b, sinfo *ai, sinfo *bi)
{
    DLList *sp;
    int i, j;
    int pivot;
    int max, min;

    sp = *a;
    i = -1;
    find_value(&max, &min, *a, ai->unsortele);
    while (++i < (ai->unsortele / 2))
        sp = sp->rlink;
    if (sp->data == max || sp->data == min)
        sp = sp->rlink;
    if (sp->data == max || sp->data == min)
        sp = sp->rlink;
    pivot = sp->data;
    i = 0;
    j = ai->unsortele;
    sp = *a;
    printf("pivot : %d\n", pivot);
    while (i < j)
    {
        if (sp->data > pivot)
            p(b, a, 'b', ai, bi);
        else
            r(a, 'a');
        print(*a, *b, ai, bi);
        sp = sp->rlink;
        i++;
    }
    sorted_insert_a(a, ai);
}

void divide_b(DLList **a, DLList **b, sinfo *ai, sinfo *bi)
{
    DLList *sp;
    int i, j;
    int pivot;
    int max, min;

    sp = *b;
    i = -1;
    find_value(&max, &min, *b, bi->curele);
    while (++i < (bi->curele / 2))
        sp = sp->rlink;
    if (sp->data == max || sp->data == min)
        sp = sp->rlink;
    if (sp->data == max || sp->data == min)
        sp = sp->rlink;
    pivot = sp->data;
    i = 0;
    j = bi->curele;
    sp = *b;
    printf("pivot : %d\n", pivot);
    while (i < j)
    {
        if (sp->data <= pivot)
            p(a, b, 'a', ai, bi);
        else
            r(b, 'b');
        print(*a, *b, ai, bi);
        sp = sp->rlink;
        i++;
        print(*a, *b, ai, bi);
    }
}

int main(int argc, char *argv[])
{
    DLList *a, *b;
    sinfo ai, bi;
    int max, min;
    int cnt = 0;
    
    int debug = 0;

    init(&a);
    init(&b);
    if (argc == 1)
        return 0;
    init_sinfo(&ai, argc - 1);
    init_sinfo(&bi, 0);
    insert_a(argc, argv, &a);

    printf("================= before =================\n");
    print(a, b, &ai, &bi);
    
    while (ai.sortele < argc - 1) // b스택 조건을 모르게따
    {
        if (ai.unsortele == 1)
        {
            if (ai.curele > 1)
                r(&a, 'a');
            ai.unsortele--;
            ai.sortele++;
        }
        else if (ai.unsortele == 2)
        {
            sorted_insert_a(&a, &ai);
            if (a->data > a->rlink->data)
                s(&a, 'a');      // ra해도됨
            if (ai.unsortele != 0)
            {
                print(a, b, &ai, &bi);
                r(&a, 'a');
                r(&a, 'a');
            }
            ai.unsortele -= 2;
            ai.sortele += 2;
        }
        while (ai.unsortele > 2)
        {
            divide_a(&a, &b, &ai, &bi);
        }
        sorted_insert_a(&a, &ai);
        if (bi.curele == 1)
        {
            p(&a, &b, 'a', &ai, &bi);
            r(&a, 'a');
        }
        else if (bi.curele == 2 && ai.unsortele == 0)
        {
            if (b->data < b->rlink->data)
                r(&b, 'b');
            sorted_insert_b(&a, &b, &ai, &bi);
        }
        divide_b(&a, &b, &ai, &bi);
    }

    printf("================= after =================\n");
    print(a, b, &ai, &bi);

    return 0;
}