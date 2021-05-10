/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tex_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:06:37 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 17:20:52 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sinfo(t_info *info, t_sinfo *s, int i)
{
	(s->sprite).x = info->sp[info->sp_order[i]].x - info->pos_x;
	(s->sprite).y = info->sp[info->sp_order[i]].y - info->pos_y;
	s->invdet = 1.0 / (info->plane_x * info->dir_y - \
			info->dir_x * info->plane_y);
	(s->transform).x = s->invdet * (info->dir_y * (s->sprite).x - \
			info->dir_x * (s->sprite).y);
	(s->transform).y = s->invdet * (-info->plane_y * \
			(s->sprite).x + info->plane_x * (s->sprite).y);
	s->sprite_screenx = (int)((info->r).width / 2) * \
						(1 + (s->transform).x / (s->transform).y);
	s->sprite_height = abs((int)((info->r).height / (s->transform).y));
	(s->draw_start).y = -s->sprite_height / 2 + (info->r).height / 2;
	if ((s->draw_start).y < 0)
		(s->draw_start).y = 0;
	(s->draw_end).y = s->sprite_height / 2 + (info->r).height / 2;
	if ((s->draw_end).y >= (info->r).height)
		(s->draw_end).y = (info->r).height - 1;
	s->sprite_width = abs((int)((info->r).height / (s->transform).y));
	(s->draw_start).x = -s->sprite_width / 2 + s->sprite_screenx;
	if ((s->draw_start).x < 0)
		(s->draw_start).x = 0;
	(s->draw_end).x = s->sprite_width / 2 + s->sprite_screenx;
	if ((s->draw_end).x >= (info->r).width)
		(s->draw_end).x = (info->r).width - 1;
}

void	bsort_sp(t_info *info)
{
	int		i;
	int		j;
	int		otmp;
	double	dtmp;

	i = info->scnt;
	while (--i >= 0)
	{
		j = info->scnt;
		while (--j >= 1)
		{
			if (info->sp_dist[j] > info->sp_dist[j - 1])
			{
				dtmp = info->sp_dist[j];
				otmp = info->sp_order[j];
				info->sp_dist[j] = info->sp_dist[j - 1];
				info->sp_order[j] = info->sp_order[j - 1];
				info->sp_dist[j - 1] = dtmp;
				info->sp_order[j - 1] = otmp;
			}
		}
	}
}

void	repeat_stripe(t_info *info, t_sinfo *s, int i, int sp)
{
	int y;
	int d;
	int color;

	while (++sp < (s->draw_end).x)
	{
		(s->tex).x = (int)(256 * (sp - (-s->sprite_width / 2 + \
				s->sprite_screenx)) * TEX_WIDTH / s->sprite_width) / 256;
		if ((s->transform).y > 0 && sp > 0 && sp < (info->r).width &&\
				(s->transform).y < info->zbuf[sp])
		{
			y = (s->draw_start).y - 1;
			while (++y < (s->draw_end).y)
			{
				d = y * 256 - (info->r).height * 128 + \
					s->sprite_height * 128;
				(s->tex).y = ((d * TEX_HEIGHT) / \
						s->sprite_height) / 256;
				color = info->texture[info->sp[info->sp_order[i]].\
						texture][TEX_WIDTH * (s->tex).y + (s->tex).x];
				if ((color & 0x00FFFFFF) != 0)
					info->buf[y][sp] = color;
			}
		}
	}
}

void	sprite_ray(t_info *info)
{
	t_sinfo	sinfo;
	int		i;

	i = 0;
	while (i < info->scnt)
	{
		info->sp_order[i] = i;
		info->sp_dist[i] = (info->pos_x - info->sp[i].x) * (info->pos_x - \
				info->sp[i].x) + (info->pos_y - info->sp[i].y) * (info->pos_y\
					- info->sp[i].y);
		i++;
	}
	bsort_sp(info);
	i = -1;
	while (++i < info->scnt)
	{
		init_sinfo(info, &sinfo, i);
		repeat_stripe(info, &sinfo, i, (sinfo.draw_start).x - 1);
	}
}
