/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:26:29 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/05 12:30:39 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_equal(char *str)
{
	int	i;
	int	idx;

	i = -1;
	idx = -1;
	while (str[++i])
		if (str[i] == '=' && idx == -1)
			idx = i;
	return (idx);
}

int	chk_key_exception(char *key, int flag)
{
	int	i;
	int	plus;

	i = 0;
	plus = 0;
	if (ft_isalpha(key[0]) == 0 && key[0] != '_')
		return (-1);
	while (key[++i])
	{
		if (ft_isalnum(key[i]) == 0 && key[i] != '_' && key[i] != '+')
			return (-1);
		if (flag == -2 && key[i] == '+')
			return (-1);
		if (plus > 0)
			return (-1);
		if (key[i] == '+')
			plus++;
	}
	return (0);
}

t_listnode	*insert_func(t_listnode *env, char *key, char *val)
{
	t_listnode	*p;
	int			add_flag;

	add_flag = 0;
	if (key[ft_strlen(key) - 1] == '+')
	{
		key[ft_strlen(key) - 1] = 0;
		add_flag = 1;
	}
	p = search(env, key, 0);
	if (p == 0)
		env = insert_last(env, key, val);
	else
	{
		if (p->val != 0 && val != 0 && add_flag != 1)
			free(p->val);
		if (val != 0 && add_flag == 0)
			p->val = val;
		else if (val != 0 && add_flag == 1)
			p->val = ft_cstrjoin(p->val, val);
	}
	return (env);
}

t_listnode	*insert_env(t_listnode *env, char *str)
{
	char	*key;
	char	*val;
	int		flag;

	flag = find_equal(str);
	if (flag == -1)
		flag = -2;
	if (flag == -2)
		key = ft_strdup(str);
	else
		key = ft_partstrdup(str, 0, flag - 1);
	val = 0;
	if (flag != -2)
		val = ft_partstrdup(str, flag + 1, ft_strlen(str));
	flag = chk_key_exception(key, flag);
	if (flag == -1)
	{
		printf("MINISHELL: export: `%s': not a valid identifier\n", str);
		free(key);
		if (val != 0)
			free(val);
	}
	else
		env = insert_func(env, key, val);
	return (env);
}

t_listnode	*copy_envp(t_listnode *env, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		env = insert_env(env, envp[i]);
	return (env);
}
