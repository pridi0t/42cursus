/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:16:36 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/12 05:18:12 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_alc(t_info *info)
{
	info->sp = malloc(info->scnt * sizeof(t_sprite));
	if (info->sp == 0)
		file_err(3);
	info->zbuf = malloc((info->r).width * sizeof(double));
	if (info->zbuf == 0)
		file_err(3);
	info->sp_order = malloc(info->scnt * sizeof(int));
	if (info->zbuf == 0)
		file_err(3);
	info->sp_dist = malloc(info->scnt * sizeof(double));
	if (info->sp_dist == 0)
		file_err(3);
}

void	input_sprite_num(t_info *info)
{
	int i;
	int j;
	int k;

	k = 0;
	sprite_alc(info);
	i = -1;
	while (++i < info->rlen)
	{
		j = -1;
		while (++j < info->clen)
		{
			if (info->map[i][j] == '2')
			{
				(info->sp[k]).x = i + 0.5;
				(info->sp[k]).y = j + 0.5;
				(info->sp[k]).texture = 4;
				info->map[i][j] = '0';
				k++;
			}
		}
	}
}

void	tex_check(t_info *info)
{
	if (info->no == 0 || info->so == 0 || info->we == 0 || \
			info->ea == 0 || info->s == 0)
	{
		perror("Error\ntexture error");
		exit(1);
	}
	if ((info->f).r == -1 || (info->f).g == -1 || (info->f).b == -1)
	{
		perror("Error\nF error");
		exit(1);
	}
	if ((info->c).r == -1 || (info->c).g == -1 || (info->c).b == -1)
	{
		perror("Error\nC error");
		exit(1);
	}
}
