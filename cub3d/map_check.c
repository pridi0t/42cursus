/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:02:33 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/11 01:24:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->rlen)
	{
		j = 0;
		while (j < info->clen)
		{
			if (!(info->map[i][j] >= '0' && info->map[i][j] <= '2') &&\
					info->map[i][j] != ' ')
				arr_free(info, 4);
			else if (info->map[i][j] == '2')
				info->scnt++;
			j++;
		}
		i++;
	}
}

void	input_sloc(t_info *info, int i, char c)
{
	(info->sloc).respawn = c;
	(info->sloc).r = i;
	(info->sloc).c = ft_strchr(info->map[i], c) - info->map[i];
	((info->sloc).cnt)++;
}

void	check_loc(t_info *info, t_loc *l)
{
	int i;

	i = 0;
	while (i < info->rlen)
	{
		if (ft_strchr(info->map[i], 'E') != 0)
			input_sloc(info, i, 'E');
		else if (ft_strchr(info->map[i], 'W') != 0)
			input_sloc(info, i, 'W');
		else if (ft_strchr(info->map[i], 'S') != 0)
			input_sloc(info, i, 'S');
		else if (ft_strchr(info->map[i], 'N') != 0)
			input_sloc(info, i, 'N');
		i++;
	}
	if ((info->sloc).cnt == 0 || (info->sloc).cnt > 1)
		arr_free(info, 5);
	else
	{
		info->map[(info->sloc).r][(info->sloc).c] = '0';
		l->r = (info->sloc).r;
		l->c = (info->sloc).c;
	}
}

int		check_rc(t_info *info, t_loc *l)
{
	if ((l->r >= 1 && info->map[l->r - 1][l->c] == ' ') ||\
			((l->r <= info->rlen - 2) && info->map[l->r + 1][l->c] == ' '))
		return (1);
	else if ((l->c >= 1 && info->map[l->r][l->c - 1] == ' ') ||\
			(l->c <= info->clen - 2 && info->map[l->r][l->c + 1] == ' '))
		return (1);
	else if (l->r == 0 || l->c == 0 ||\
			l->r == (info->rlen - 1) || l->c == (info->clen - 1))
		return (1);
	return (0);
}

int		mdfs(t_stacktype *s, t_info *info, t_loc *l)
{
	while (1)
	{
		if (check_rc(info, l) == 1)
			break ;
		info->map[l->r][l->c] = '*';
		push_loc(s, info, l->r - 1, l->c);
		push_loc(s, info, l->r + 1, l->c);
		push_loc(s, info, l->r, l->c - 1);
		push_loc(s, info, l->r, l->c + 1);
		if (is_empty(s))
			return (0);
		*l = pop(s);
	}
	printf("map check fail\n");
	return (1);
}
