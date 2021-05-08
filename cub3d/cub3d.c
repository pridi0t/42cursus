/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:01:38 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/08 15:56:11 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stack.h"
#include <mlx.h>

void	init_rinfo(t_info *info)
{
	int i;

	info->pos_x = (double)(info->sloc).r + 0.5;
	info->pos_y = (double)(info->sloc).c + 0.5;
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, (info->r).width, (info->r).height, "mlx");
	//(info->img).img = mlx_new_image(info->mlx, (info->r).width, (info->r).height);
	info->buf = ft_calloc((info->r).height, sizeof(int *));
	info->texture = ft_calloc(5, sizeof(int *));
	//(info->img).data = (int *)mlx_get_data_addr((info->img).img, &(info->img).bpp, &(info->img).size_l, &(info->img).endian);
	info->move_speed = 0.4;
	info->rot_speed = 0.3;
	for (i = 0 ; i < (info->r).height ; i++)
		info->buf[i] = ft_calloc((info->r).width, sizeof(int));
	for (i = 0 ; i < 5 ; i++)
		info->texture[i] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
}

void	calc_ray(t_info *info)
{
	int x, y;
	int color; // Uint32로 해야된다는데 머지
	t_winfo winfo;
	t_sinfo sinfo;

	cf_ray(info);
	/*
	// 천장, 바닥 캐스팅
	for (y = 0 ; y < (info->r).height ; y++)
	{
		init_cfinfo(info, &cfinfo, y);
		for (int x = 0 ; x < (info->r).width ; ++x)
		{
			color = info->texture[floorTexture][TEX_WIDTH * ty + tx];
			color = (color >> 1) & 8355711;
			(info->buf)[y][x] = color; 
			color = info->texture[ceilingTexture][TEX_WIDTH * ty + tx];
			color = (color >> 1) & 8355711;
			(info->buf)[(info->r).height - y - 1][x] = color;
		}
	}
	*/
	
	// 벽 레이캐스팅
	for (x = 0 ; x < (info->r).width ; x++)
	{
		init_winfo(info, &winfo, x);
		calc_dda(info, &winfo);
		calc_tex(info, &winfo);
		for	(y = winfo.draw_start; y < winfo.draw_end; y++)
		{
				(winfo.tex).y = (int)winfo.texpos & (TEX_HEIGHT - 1);
				winfo.texpos += winfo.dstep;
				color = info->texture[winfo.texnum][TEX_HEIGHT * (winfo.tex).y + (winfo.tex).x];
				if (winfo.side == 1)
					color = (color >> 1) & 8355711;
				info->buf[y][x] = color;
		}
		// ------ sprite의 ZBuffer 셋팅
		info->zbuf[x] = winfo.perp_wall_dist;
	}

	// sprite 캐스팅 ------------------
	int i;
	for (i = 0 ; i < info->scnt ; i++)
	{
		info->sp_order[i] = i;
		info->sp_dist[i] = (info->pos_x - info->sp[i].x) * (info->pos_x - info->sp[i].x) + (info->pos_y - info->sp[i].y) * (info->pos_y - info->sp[i].y);
	}
	bsort_sp(info);
	for (i = 0; i < info->scnt ; i++)
	{
		init_sinfo(info, &sinfo, i);
		int s;
		for (s = (sinfo.draw_start).x ; s < (sinfo.draw_end).x ; s++)
		{
			int texX = (int)(256 * (s - (-sinfo.sprite_width / 2 + sinfo.sprite_screenx)) * TEX_WIDTH / sinfo.sprite_width) / 256;
			if ((sinfo.transform).y > 0 && s > 0 && s < (info->r).width && (sinfo.transform).y < info->zbuf[s])
				for (y = (sinfo.draw_start).y ; y < (sinfo.draw_end).y ; y++)
				{
					int d = y * 256 - (info->r).height * 128 + sinfo.sprite_height * 128;
					int texY = ((d * TEX_HEIGHT) / sinfo.sprite_height) / 256;
					color = info->texture[info->sp[info->sp_order[i]].texture][TEX_WIDTH * texY + texX];
					if ((color & 0x00FFFFFF) != 0)
						info->buf[y][s] = color;
				}
		}
	}
}

void	draw(t_info *info)
{
	int x, y;

	for (y = 0 ; y < (info->r).height ; y++)
	{
		for (x = 0 ; x < (info->r).width ; x++)
			info->img.data[y * (info->r).width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, (info->img).img, 0, 0);
}

int main_loop(t_info *info)
{
	calc_ray(info);
	draw(info);
	return (0);
}

int		key_press(int key, t_info *info)
{
	double oldDirX = 0;
	double oldPlaneX = 0;

	if (key == K_W)
	{
		if ((info->map[(int)(info->pos_x + info->dir_x * info->move_speed)][(int)info->pos_y] - '0') == 0)
			info->pos_x += info->dir_x * info->move_speed;
		if ((info->map[(int)info->pos_x][(int)(info->pos_y + info->dir_y * info->move_speed)] - '0') == 0)
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (key == K_S)
	{
		if ((info->map[(int)(info->pos_x - info->dir_x * info->move_speed)][(int)info->pos_y] - '0') == 0)
			info->pos_x -= info->dir_x * info->move_speed;
		if ((info->map[(int)info->pos_x][(int)(info->pos_y - info->dir_y * info->move_speed)] - '0') == 0)
			info->pos_y -= info->dir_y * info->move_speed;
	}
	if (key == K_D)
	{
		oldDirX = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
		info->dir_y = oldDirX * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
		oldPlaneX = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
		info->plane_y = oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
	}
	if (key == K_A)
	{
		oldDirX = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
		info->dir_y = oldDirX *sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
		oldPlaneX = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
		info->plane_y = oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int y;
	int x;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (y = 0 ; y < img->img_height ; y++)
	{
		for(x = 0 ; x < img->img_width ; x++)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	load_image(info, info->texture[0], info->no, &info->img);
	load_image(info, info->texture[1], info->so, &info->img);
	load_image(info, info->texture[2], info->we, &info->img);
	load_image(info, info->texture[3], info->ea, &info->img);
	load_image(info, info->texture[4], info->s, &info->img);
}

int		main(void)
{
	t_gnl		gnl;
	t_info		info;
	t_stacktype s;
	t_loc		l;

	ft_memset(&info, 0, sizeof(info));
	init_info(&info);
	init_stack(&s);
	ft_memset(&gnl, 0, sizeof(gnl));
	call_gnl(&gnl, &info);
	alc_2arr(&info);
	convert_map(&gnl, &info);
	check_loc(&info, &l);
	check_map(&info);
	if (mdfs(&s, &info, &l) != 0)
		arr_free(&info, 4);
	convert_map(&gnl, &info);
	info.map[info.sloc.r][info.sloc.c] = '0';

	// --- 맵에서 sprite 개수 세고 동적할당해서 넣어주는 부분 ----------------------------
	int i, j, k = 0;
	info.sp = malloc(info.scnt * sizeof(t_sprite));
	
	// sprite 연산에 필요한 배열들 초기화(malloc방어 해야되나?)
	info.zbuf = malloc(info.r.width * sizeof(double));
	info.sp_order = malloc(info.scnt * sizeof(int));
	info.sp_dist = malloc(info.scnt * sizeof(double));

	for (i = 0 ; i < info.rlen ; i++)
	{
		for (j = 0 ; j < info.clen ; j++)
		{
			if (info.map[i][j] == '2')
			{
				(info.sp[k]).x = i + 0.5;  // 가운데정렬
				(info.sp[k]).y = j + 0.5;
				(info.sp[k]).texture = 4;	// sprite[]랑 대응된대
				info.map[i][j] = '0';
				k++;
			}
		}
	}
	// ------------------------------------------------------------------------
	
	// ------------------ 레이캐스팅 시작
	init_rinfo(&info);
	// malloc 확인하는 함수부분 있는데 지웠음
	load_texture(&info);
	
	(info.img).img = mlx_new_image(info.mlx, (info.r).width, (info.r).height);
	(info.img).data = (int *)mlx_get_data_addr((info.img).img, &(info.img).bpp, &(info.img).size_l, &(info.img).endian);
	
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	
	mlx_loop(info.mlx);
	return (0);
}
