#include <stdio.h>
#include "server.h"

void add_last(int pid)
{
	t_cllist *p;
	t_cllist *tmp;

	p = (t_cllist *)malloc(sizeof(t_cllist));
	p->pid = pid;
	p->str = NULL;
	if (g_l == NULL)
	{
		g_l = p;
		p->link = p;
		return ;
	}
	tmp = g_l;
	while (tmp->link != g_l)
		tmp = tmp->link;
	tmp->link = p;
	p->link = g_l;
}

int search(int pid)
{
	t_cllist *p;

	if (g_l == NULL)
		return (0);
	p = g_l->link;
	while (p != g_l)
	{
		if (p->pid == pid)
			return (1);
		p = p->link;
	}
	return (0);
}

void delete_node(int pid)
{
	t_cllist *pre;
	t_cllist *cur;

	if (g_l == g_l->link && g_l->pid == pid)
	{
		g_l = NULL;
		return ;
	}
	else if (g_l->pid == pid)
	{
		cur = g_l->link;
		free(g_l);
		g_l = cur;
		return ;
	}
	pre = g_l;
	cur = g_l->link;
	while (cur->pid != pid)
	{
		pre = cur;
		cur = cur->link;
	}
	pre->link = cur->link;
	free(cur);
}

void print_list(void)
{
	t_cllist *p;
	char	*tmp;

	if (g_l == NULL)
	{
		printf("NULL\n");
		return ;
	}
	tmp = ft_itoa(g_l->pid);
	write(1, tmp, ft_strlen(tmp));
	write(1, " ", 1);
	p = g_l->link;
	while (p != g_l)
	{
		tmp = ft_itoa(p->pid);
		write(1, tmp, ft_strlen(tmp));
		write(1, " ", 1);
		p = p->link;
	}
}
