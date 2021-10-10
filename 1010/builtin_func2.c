/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:00:16 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 17:45:50 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **args)
{
	(void)args;
	printf("exit\n");
	exit(1);
}

void	selection_sort(t_listnode **tmp)
{
	int			i;
	int			j;
	int			len;
	t_listnode	*t_tmp;

	i = -1;
	while (tmp[++i])
	{
		j = i;
		while (tmp[++j])
		{
			if (ft_strlen(tmp[i]->key) > ft_strlen(tmp[j]->key))
				len = ft_strlen(tmp[i]->key) + 1;
			else
				len = ft_strlen(tmp[j]->key) + 1;
			if (ft_strncmp(tmp[i]->key, tmp[j]->key, len) > 0)
			{
				t_tmp = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = t_tmp;
			}
		}
	}	
}

void	prt_export(t_listnode **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i]->val != 0)
			printf("declare -x %s=\"%s\"\n", tmp[i]->key, tmp[i]->val);
		else
			printf("declare -x %s\n", tmp[i]->key);
	}
}

void	ft_export(char **args, t_listnode **env)
{
	int			i;
	t_listnode	**tmp;
	t_listnode	*p;

	i = 0;
	p = *env;
	while (args[++i])
		*env = insert_env(*env, args[i]);
	if (i == 1)
	{
		tmp = malloc(sizeof(t_listnode *) * (get_nlen(*env) + 1));
		i = 0;
		while (p != 0)
		{
			tmp[i] = p;
			p = p->link;
			i++;
		}
		tmp[i] = 0;
		selection_sort(tmp);
		prt_export(tmp);
		free(tmp);
	}
}

void	ft_unset(char **args, t_listnode **env)
{
	int			i;
	t_listnode	*p;
	t_listnode	*pre;

	p = *env;
	i = 0;
	pre = 0;
	while (args[++i])
	{
		while (p != 0)
		{
			if (ft_strncmp(p->key, args[i], ft_strlen(args[i])) == 0)
			{
				if (pre == 0)
					*env = delete_first(*env);
				else
					delete(*env, pre);
				break ;
			}
			pre = p;
			p = p->link;
		}
	}
}
