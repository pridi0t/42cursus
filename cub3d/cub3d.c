/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/07 06:35:45 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stack.h"
#include <mlx.h>
#include <math.h>
#include <unistd.h>

void	init_rinfo(t_info *info)
{
	int i;

	info->posX = (double)(info->sloc).r;
	info->posY = (double)(info->sloc).c;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, (info->r).width, (info->r).height, "mlx");
	//(info->img).img = mlx_new_image(info->mlx, (info->r).width, (info->r).height);
	info->buf = ft_calloc((info->r).height, sizeof(int *));
	info->texture = ft_calloc(5, sizeof(int *));
	//(info->img).data = (int *)mlx_get_data_addr((info->img).img, &(info->img).bpp, &(info->img).size_l, &(info->img).endian);
	info->moveSpeed = 0.2;
	info->rotSpeed = 0.1;

	for (i = 0 ; i < (info->r).height ; i++)
		info->buf[i] = ft_calloc((info->r).width, sizeof(int));
	for (i = 0 ; i < 5 ; i++)
		info->texture[i] = ft_calloc(tex_height * tex_width, sizeof(int));
}

void	calc_ray(t_info *info)
{
	int x;
	
	for (x = 0 ; x < (info->r).width ; x++)
	{
		double cameraX = 2 * x / (double)(info->r).width - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;
		
		// 1. DDA 알고리즘에 필요한 변수 계산
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1/ rayDirY);
		double perp_Wall_Dist;

		int stepX;
		int stepY;
		
		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		// 2. 알고리즘 계산
		while (hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if ((info->map[mapX][mapY] - '0') > 0) hit = 1;
		}
		// 벽까지의 거리 계산, 어안렌즈 보정
		if (side == 0)
			perp_Wall_Dist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perp_Wall_Dist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		// 화면에 그릴 벽의 길이 계산
		int lineHeight = (int) ((info->r).height / perp_Wall_Dist);

		int drawStart = -lineHeight / 2 + (info->r).height / 2;
		if (drawStart < 0) 
			drawStart = 0;
		int drawEnd = lineHeight / 2 + (info->r).height / 2;
		if (drawEnd >= (info->r).height) 
			drawEnd = (info->r).height - 1;

		// 텍스쳐 선택, 충돌 지점과 텍스쳐의 x좌표값 계산
		int texNum = (info->map[mapX][mapY] - '0');

		double wallX;
		if (side == 0) 
			wallX = info->posY + perp_Wall_Dist * rayDirY;
		else 
			wallX = info->posX + perp_Wall_Dist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)tex_width);
		if (side == 0 && rayDirX > 0) 
			texX = tex_width - texX - 1;
		if (side == 1 && rayDirY < 0) 
			texX = tex_width - texX - 1;

		// 텍스쳐의 y 좌표값
		double step = 1.0 * tex_height / lineHeight;

		double texPos = (drawStart - (info->r).height / 2 + lineHeight / 2) * step;
		int y;
		for	(y = 0; y < info->r.height; y++)
		{
			if (y < drawStart)
				info->buf[y][x] = 0xffffff;
			else if (y < drawEnd)
			{
				int texY = (int)texPos & (tex_height - 1);
				texPos += step;
				int color = info->texture[texNum][tex_height * texY + texX];;
				if (side == 1) 
					color = (color >> 1) & 8355711;
				info->buf[y][x] = color;
			}
			else
				info->buf[y][x] = 0x000000;
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
		if (!(info->map[(int)(info->posX + info->dirX * info->moveSpeed)][(int)info->posY] - '0'))
			info->posX += info->dirX * info->moveSpeed;
		if (!(info->map[(int)info->posX][(int)(info->posY + info->dirY * info->moveSpeed)] - '0'))
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == K_S)
	{
		if (!(info->map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)info->posY] - '0'))
			info->posX -= info->dirX * info->moveSpeed;
		if (!(info->map[(int)info->posX][(int)(info->posY - info->dirY * info->moveSpeed)] - '0'))
			info->posY -= info->dirY * info->moveSpeed;
	}
	if (key == K_D)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	if (key == K_A)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX *sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
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
	for (int i = 0; i < info.rlen; i++)
		printf("%s\n",info.map[i]);
	
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
