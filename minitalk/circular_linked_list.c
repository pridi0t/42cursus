#include <stdio.h>
#include "server.h"

void add_last(int pid)
{
	t_cllist *p;
	t_cllist *tmp;

	p = (t_cllist *)malloc(sizeof(t_cllist));
	p->pid = pid;
	ft_memset(p->bin, -1, sizeof(p->bin));
	p->str_size = 100;
	p->str = (char *)malloc(p->str_size);
	ft_memset(p->str, 0, sizeof(p->str_size));
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

t_cllist *search(int pid)
{
	t_cllist *p;

	if (g_l == NULL)
		return (NULL);
	if (g_l->pid == pid)
		return (g_l);
	p = g_l->link;
	while (p != g_l)
	{
		if (p->pid == pid)
			return (p);
		p = p->link;
	}
	return (NULL);
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
	//char	*tmp;
	int i;

	if (g_l == NULL)
	{
		printf("NULL\n");
		return ;
	}
	//tmp = ft_itoa(g_l->pid);
	printf("==================\n");
	printf("pid : %d\n", g_l->pid);
	printf("bin : ");
	i = -1;
	while (g_l->bin[++i] != -1)
		printf("%d", g_l->bin[i]);
	printf("\nstr : %s", g_l->str);
	printf("\n==================\n");
	p = g_l->link;
	while (p != g_l)
	{
		//tmp = ft_itoa(p->pid);
		printf("==================\n");
		printf("pid : %d\n", p->pid);
		printf("bin : ");
		i = -1;
		while (p->bin[++i] != -1)
			printf("%d", p->bin[i]);
		printf("\nstr : %s", p->str);
		printf("\n==================\n");
		p = p->link;
	}
}
