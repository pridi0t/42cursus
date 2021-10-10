/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:46:02 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/10 19:58:10 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tolower_str(char *str)
{
	int	i;
	int	strlen;

	i = -1;
	strlen = ft_strlen(str);
	while (++i < strlen)
		str[i] = ft_tolower(str[i]);
}

int	chk_builtins(char **args, t_listnode **env)
{
	if (ft_strncmp(args[0], "export\0", 7) == 0)
		ft_export(args, env);
	else if (ft_strncmp(args[0], "unset\0", 6) == 0)
		ft_unset(args, env);
	else if (ft_strncmp(args[0], "exit\0", 5) == 0)
		ft_exit(args);
	else
	{
		tolower_str(args[0]);
		if (ft_strncmp(args[0], "echo\0", 5) == 0)
			ft_echo(args);
		else if (ft_strncmp(args[0], "cd\0", 3) == 0)
			ft_cd(args, env);
		else if (ft_strncmp(args[0], "pwd\0", 4) == 0)
			ft_pwd();
		else if (ft_strncmp(args[0], "env\0", 4) == 0)
			ft_env(*env);
		else
			return (0);
	}
	return (1);
}
