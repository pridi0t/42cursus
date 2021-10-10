/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 01:53:31 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/10 19:58:00 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_listnode *env)
{
	t_listnode	*p;

	p = env;
	while (p != 0)
	{
		if (p->val != NULL)
			printf("%s=%s\n", p->key, p->val);
		p = p->link;
	}
}

void	ft_pwd(void)
{
	char		*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		printf("MINISHELL: getcwd error\n");
		return ;
	}
	printf("%s\n", path);
	free(path);
}
