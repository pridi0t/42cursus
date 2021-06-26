#include <stdio.h>
#include "server.h"

void add_last(t_cllist **l, int pid)
{
	t_cllist *p;
	t_cllist *tmp;

	p = (t_cllist *)malloc(sizeof(t_cllist));
	p->pid = pid;
	p->str = NULL;
	if (*l == NULL)
	{
		*l = p;
		p->link = p;
		return ;
	}
	tmp = p;
	while (tmp->link != *l)
		tmp = tmp->link;
	tmp->link = p;
	p->link = *l;
}

int search(t_cllist **l, int pid)
{
	t_cllist *p;

	p = *l;
	while (p->link != *l)
	{
		if (p->pid == pid)
			return (1);
		p = p->link;
	}
	return (0);
}

void delete_node(t_cllist **l, int pid)
{
	t_cllist *pre;
	t_cllist *cur;

	if (*l == (*l)->link && (*l)->pid == pid)
	{
		*l = NULL;
		return ;
	}
	pre = *l;
	cur = (*l)->link;
	while (cur->pid != pid)
	{
		pre = cur;
		cur = cur->link;
	}
	pre->link = cur->link;
	free(cur);
}

void print_list(t_cllist *l)
{
	t_cllist *p;

	if (l == NULL)
		return ;
	printf("%d : %s\n", l->pid, l->str);
	p = l->link;
	while (p->link != l)
	{
		printf("%d : %s\n", l->pid, l->str);
		p = p->link;
	}
}
