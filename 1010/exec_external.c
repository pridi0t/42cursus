/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:43:54 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/10 21:54:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

char	**node_to_array(t_listnode *head)
{
	t_listnode	*p;
	int			i;
	char		**arr;

	p = head;
	i = 0;
	while (p != NULL)
	{
		i++;
		p = p->link;
	}
	arr = malloc(sizeof(char *) * (i + 1));
	p = head;
	i = 0;
	while (p != NULL)
	{
		arr[i] = ft_strdup(p->key);
		arr[i] = ft_cstrjoin(arr[i], "=");
		arr[i] = ft_cstrjoin(arr[i], p->val);
		p = p->link;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	proc(char *path, char **args, char **envp)
{
	pid_t	pid;
	pid_t	tpid;

	pid = fork();
	if (pid > 0)
	{
		tpid = wait(NULL);
		if (tpid == -1)
			return (-1);
		return (0);
	}
	else if (pid == 0)
	{
		if (execve(path, args, envp) == -1)
			return (-1);
		return (1);
	}
	printf("fork Fail! \n");
	return (-1);
}

int	without_path(char *com)
{
	char	*path;

	path = 

}

int	exec_external(char **args, t_listnode *env)
{
	int			i;
	int			result;
	t_listnode	*tmp;
	char		**arr;
	char		**cenv;
	struct stat	fi;

	// start . .. /
	tmp = search(env, "PATH", NULL);
	if (tmp == NULL)
	{
		// without_path()
		// return (0);
	}
	arr = ft_split(tmp->val, ':');
	i = -1;
	while (arr[++i] != NULL)
	{
		arr[i] = ft_cstrjoin(arr[i], "/");
		arr[i] = ft_cstrjoin(arr[i], args[0]);
		if (stat(arr[i], &fi) != -1)
		{
			if ((fi.st_mode & S_IFMT) != S_IFREG)
				continue ;
			cenv = node_to_array(env);
			result = proc(arr[i], args, cenv);
			if (result == 1)
				break ;
			else if (result == -1)
				return (-1);
			cenv = free_arr(cenv);
		}
	}
	arr = free_arr(arr);
	return (0);
}
