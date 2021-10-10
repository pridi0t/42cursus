/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:33:56 by jitlee            #+#    #+#             */
/*   Updated: 2021/10/06 16:42:08 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	put_buf(t_parse *d, t_listnode **env)
{
	int			i;
	char		*arg;
	t_listnode	*find;

	i = ++(d->i);
	if (ft_isdigit(d->str[d->i]))
		return ;
	while (ft_isalnum(d->str[d->i]))
		d->i += 1;
	if (d->i == i)
	{
		d->pstr[(d->j)++] = '$';
		return ;
	}
	d->i -= 1;
	arg = ft_partstrdup(d->str, i, d->i);
	find = search(*env, arg, 0);
	i = -1;
	if (find != 0)
		while (find->val[++i])
			d->pstr[(d->j)++] = find->val[i];
}

void	chk_empty(t_parse *d)
{
	if (d->i - d->cnt == 1)
		d->pstr[(d->j)++] = -1;
}

int	ctrl_mode(t_parse *d)
{
	if (d->str[d->i] == '\'' && d->cur == SQ_MODE)
	{
		chk_empty(d);
		d->cur = NO_MODE;
		return (1);
	}
	else if (d->str[d->i] == '\'' && d->cur == NO_MODE)
	{
		d->cnt = d->i;
		d->cur = SQ_MODE;
		return (1);
	}
	else if (d->str[d->i] == '\"' && d->cur == DQ_MODE)
	{
		chk_empty(d);
		d->cur = NO_MODE;
		return (1);
	}
	else if (d->str[d->i] == '\"' && d->cur == NO_MODE)
	{
		d->cnt = d->i;
		d->cur = DQ_MODE;
		return (1);
	}
	return (0);
}

char	*parsing_str(t_listnode **env, char *str)
{
	t_parse	d;

	d.cur = NO_MODE;
	d.i = -1;
	d.j = 0;
	d.inc = 1;
	d.str = str;
	d.pstr = malloc(BUFFER_SIZE);
	while (d.str[++(d.i)])
	{
		if (d.i + 2 > BUFFER_SIZE * d.inc)
			d.pstr = increase_malloc(d.pstr, ++(d.inc));
		if (d.cur != SQ_MODE && d.str[d.i] == '$')
			put_buf(&d, env);
		else if (ctrl_mode(&d))
			;
		else
			d.pstr[(d.j)++] = d.str[d.i];
	}
	d.pstr[d.j] = 0;
	return (d.pstr);
}
