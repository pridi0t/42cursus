/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tex_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:06:37 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/08 15:43:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_sinfo(t_info *info, t_sinfo *s, int i)
{
    (s->sprite).x = info->sp[info->sp_order[i]].x - info->pos_x;
    (s->sprite).y = info->sp[info->sp_order[i]].y - info->pos_y;
    s->invdet = 1.0 / (info->plane_x * info->dir_y - info->dir_x * info->plane_y);
    (s->transform).x = s->invdet * (info->dir_y * (s->sprite).x - info->dir_x * (s->sprite).y);
    (s->transform).y = s->invdet * (-info->plane_y * (s->sprite).x + info->plane_x * (s->sprite).y);
    s->sprite_screenx = (int)((info->r).width / 2) * (1 + (s->transform).x / (s->transform).y);
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

// sprite 정렬 함수
// (거리가 먼쪽이 앞에옴) 내림차순이길래 역으로 돌려봤음
void	bsort_sp(t_info *info)
{
	int i, j;
	int otmp;
	double dtmp;

	for (i = info->scnt - 1 ; i >= 0 ; i--)
	{
		for (j = info->scnt - 1 ; j >= 1 ; j--)
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