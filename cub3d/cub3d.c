/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:01:38 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/12 02:13:22 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_err(int errno)
{
	if (errno == 1)
		perror("no .cub file");
	else if (errno == 2)
		perror("argv error");
	else if (errno == 3)
		perror("wrong option");
	else if (errno == 4)
		perror("bmp save error");
	exit(1);
}

void	write_file(int fd, int value, int byte)
{
	write(fd, &value, byte);
}

void	save_bmp(t_info *info)
{
	int fd;
	int tmp;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		main_err(4);
	write(fd, "B", 1);
	write(fd, "M", 1);
	write_file(fd, 54 + 4 * (info->r).width * (info->r).height, 4);
	write_file(fd, 0, 4);
	write_file(fd, 54, 4);
	write_file(fd, 40, 4);
	write_file(fd, (info->r).width, 4);
	write_file(fd, -(info->r).height, 4);
	write_file(fd, 1, 2);
	write_file(fd, 32, 2);
	write_file(fd, 0, 4);
	write_file(fd, 4 * (info->r).width * (info->r).height, 4);
	write_file(fd, (info->r).width, 4);
	write_file(fd, (info->r).height, 4);
	write_file(fd, 0x00ffffff, 4);
	write_file(fd, 0, 4);
	tmp = -1;
	while (++tmp < info->r.width * info->r.height)
		write(fd, &info->img.data[tmp], 4);
}

void	check_cub(int argc, char *argv[], t_info *info)
{
	info->save = 0;
	if (argc == 1)
		main_err(1);
	if (argc > 3)
		main_err(2);
	if (ft_strlen(argv[1]) < 4)
		main_err(2);
	else if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		main_err(2);
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 && ft_strncmp(argv[2], "--save", 6) == 0)
			info->save = 1;
		else
			main_err(3);
	}
}

int		main(int argc, char *argv[])
{
	t_gnl		gnl;
	t_info		info;
	t_stacktype s;
	t_loc		l;

	ft_memset(&info, 0, sizeof(info));
	check_cub(argc, argv, &info);
	init_info(&info);
	init_stack(&s);
	ft_memset(&gnl, 0, sizeof(gnl));
	call_gnl(&gnl, &info, argv[1]);
	info_check(&info);
	alc_2arr(&info);
	convert_map(&gnl, &info, argv[1]);
	check_loc(&info, &l);
	check_map(&info);
	if (mdfs(&s, &info, &l) != 0)
		arr_free(&info, 4);
	convert_map(&gnl, &info, argv[1]);
	info.map[(info.sloc).r][(info.sloc).c] = '0';
	input_sprite_num(&info);
	raycasting(&info);
	return (0);
}
