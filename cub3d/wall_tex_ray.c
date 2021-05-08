/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tex_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:05:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/08 15:05:44 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_winfo(t_info *info, t_winfo *w, int x)
{
    w->camerax = 2 * x / (double)(info->r).width - 1;
    (w->raydir).x = info->dir_x + info->plane_x * w->camerax;
    (w->raydir).y = info->dir_y + info->plane_y * w->camerax;
    (w->map).x = (int)info->pos_x;
    (w->map).y = (int)info->pos_y;
    (w->deltadist).x = fabs(1 / (w->raydir).x);
    (w->deltadist).y = fabs(1 / (w->raydir).y);
    w->hit = 0;
    (w->step).x = 1;
    (w->sidedist).x = ((w->map).x + 1.0 - info->pos_x) * (w->deltadist).x;
    if ((w->raydir).x < 0)
    {
        (w->step).x = -1;
        (w->sidedist).x = (info->pos_x - (w->map).x) * (w->deltadist).x;
    }
    (w->step).y = 1;
    (w->sidedist).y = ((w->map).y + 1.0 - info->pos_y) * (w->deltadist).y;
    if ((w->raydir).y < 0)
    {
        (w->step).y = -1;
        (w->sidedist).y = (info->pos_y - (w->map).y) * (w->deltadist).y;
    }
}

void calc_dda(t_info *info, t_winfo *w)
{
    while (w->hit == 0)
    {
        if((w->sidedist).x < (w->sidedist).y)
        {
            (w->sidedist).x += (w->deltadist).x;
            (w->map).x += (w->step).x;
            w->side = 0;
        }
        else
        {
            (w->sidedist).y += (w->deltadist).y;
            (w->map).y += (w->step).y;
            w->side = 1;
        }
        if ((info->map[(w->map).x][(w->map).y] - '0') > 0) 
            w->hit = 1;
    }
    w->perp_wall_dist = ((w->map).x - info->pos_x + (1 - (w->step).x) / 2) / (w->raydir).x;
    if (w->side == 1)
        w->perp_wall_dist = ((w->map).y - info->pos_y + (1 - (w->step).y) / 2) / (w->raydir).y;
    w->lineheight = (int)((info->r).height / w->perp_wall_dist);
    w->draw_start = -w->lineheight / 2 + (info->r).height / 2;
    if (w->draw_start < 0)
        w->draw_start = 0;
    w->draw_end = w->lineheight / 2 + (info->r).height / 2;
    if (w->draw_end >= (info->r).height) 
        w->draw_end = (info->r).height - 1;
}

void calc_tex(t_info *info, t_winfo *w)
{
    w->texnum = info->map[(w->map).x][(w->map).y] - '0';
    w->wallx = info->pos_y + w->perp_wall_dist * (w->raydir).y;
    if (w->side == 1)
        w->wallx = info->pos_x + w->perp_wall_dist * (w->raydir).x;
    w->wallx -= floor(w->wallx);
    (w->tex).x = (int)(w->wallx * (double)TEX_WIDTH);
    if (w->side == 0 && (w->raydir).x > 0)
        (w->tex).x = TEX_WIDTH - (w->tex).x - 1;
    if (w->side == 1 && (w->raydir).y < 0)
        (w->tex).x = TEX_WIDTH - (w->tex).x - 1;
    w->dstep = 1.0 * TEX_HEIGHT / w->lineheight;
    w->texpos = (w->draw_start - (info->r).height / 2 + w->lineheight / 2) * w->dstep;
}
