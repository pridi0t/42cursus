/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:29:11 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 19:27:36 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prt_unknown_cmd(char *str)
{
	int		i;
	char	*cmd;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			break ;
	cmd = ft_partstrdup(str, 0, i - 1);
	printf("MINISHELL: %s: command not found\n", cmd);
	free(cmd);
}

int	main(int ac, char **av, char **envp)
{
	t_listnode	*env;
	char		*str;
	char		*pstr;
	char		**args;

	(void)ac;
	(void)av;
	env = 0;
	env = copy_envp(env, envp);
	while (1)
	{
		str = readline("MINISHELL$ ");
		pstr = parsing_str(&env, str);
		args = ft_csplit(pstr, " \t");
		if (args[0] == 0)
			continue ;
		if (chk_builtins(args, &env) == 0)
		{
			if (exec_external(args, env) == 0)
				prt_unknown_cmd(pstr);
		}
		add_history(str);
		free(pstr);
		free(str);
		free(args);
	}
	return (0);
}
