/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:45:28 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 16:49:51 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
	int	i;
	int	args_len;
	int	flag;

	flag = 0;
	args_len = 0;
	while (args[args_len])
		args_len++;
	if (args_len > 1 && ft_strncmp(args[1], "-n", 3) == 0)
		flag = 1;
	i = flag;
	while (args[++i])
	{
		if (i + 1 < args_len)
			printf("%s ", args[i]);
		else
			printf("%s", args[i]);
	}
	if (!flag)
		printf("\n");
}
