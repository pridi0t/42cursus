/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:41:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/10 19:50:21 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(t_listnode *env)
{
	t_listnode	*pwd;
	char		*path;

	pwd = search(env, "PWD", NULL);
	if (pwd != NULL)
	{
		path = getcwd(NULL, 0);
		free(pwd->val);
		pwd->val = path;
	}
}

int	cd_home(char **args, t_listnode **env)
{
	t_listnode	*tmp;

	if (args[1] == 0)
	{
		tmp = search(*env, "HOME", NULL);
		if (tmp == NULL)
		{
			printf("MINISHELL: cd: HOME not set\n");
			return (-1);
		}
		if (chdir(tmp->val) == -1)
		{
			printf("MINISHELL: cd: %s: No such \
					file or directory\n", tmp->val);
			return (-1);
		}
		change_pwd(*env);
		return (1);
	}
	return (0);
}

t_listnode	*convert_lpwd(void)
{
	int			i;
	char		*path;
	char		**spath;
	t_listnode	*pwd;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return (NULL);
	spath = ft_split(path, '/');
	pwd = NULL;
	i = -1;
	while (spath[++i] != NULL)
		pwd = insert_last(pwd, 0, ft_strdup(spath[i]));
	spath = free_arr(spath);
	free(path);
	return (pwd);
}

t_listnode	*io_pwd(char **args, t_listnode *pwd)
{
	int			i;
	char		**spwd;

	spwd = ft_split(args[1], '/');
	if (args[1][0] == '/')
		while (pwd != NULL)
			pwd = delete_first(pwd);
	i = -1;
	while (spwd[++i] != NULL)
	{
		if (ft_strncmp(spwd[i], "..", 3) == 0)
			pwd = delete_last(pwd);
		else if (ft_strncmp(spwd[i], ".", 2) == 0)
			continue ;
		else
			pwd = insert_last(pwd, 0, ft_strdup(spwd[i]));
	}
	spwd = free_arr(spwd);
	return (pwd);
}

void	ft_cd(char **args, t_listnode **env)
{
	char		*str;
	t_listnode	*tmp_pwd;

	if (cd_home(args, env) != 0)
		return ;
	tmp_pwd = convert_lpwd();
	tmp_pwd = io_pwd(args, tmp_pwd);
	str = ft_strdup("/");
	while (tmp_pwd != NULL)
	{
		str = ft_cstrjoin(str, tmp_pwd->val);
		tmp_pwd = delete_first(tmp_pwd);
		if (tmp_pwd != NULL)
			str = ft_cstrjoin(str, "/");
	}
	if (chdir(str) == -1)
	{
		printf("MINISHELL: cd: %s: No such file or directory\n", args[1]);
		return ;
	}
	change_pwd(*env);
	if (str != NULL)
		free(str);
}
