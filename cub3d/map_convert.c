/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:49:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/30 00:37:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_err(int errno)
{
	if (errno == 1)
		perror("Error\nFile open error");
	else if (errno == 2)
		perror("Error\nFile close error");
	else if (errno == 3)
		perror("Error\nMalloc error");
	else if (errno == 4)
		perror("Error\nInvalid map");
	exit(1);
}

void	arr_free(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
	file_err(3);
}

void	call_gnl(t_gnl *gnl, t_info *info)
{
	int flag;

	flag = 0;
	gnl->result = 1;
	gnl->fd = open("1.cub", O_RDONLY);
	if (gnl->fd != 3)
		file_err(1);
	while (gnl->result > 0)
	{
		gnl->result = get_next_line(gnl->fd, &gnl->line);
		if (flag == 1 && ft_strlen(gnl->line) == 0)
			file_err(4);
		else if (ft_strlen(gnl->line) != 0)
			input_info(info, gnl->line, &flag);
		if (flag == 0)
			(info->iflen)++;
		free(gnl->line);
	}
	if (close(gnl->fd) != 0)
		file_err(2);
}

void	convert_map(t_gnl *gnl, t_info *info)
{
	int i;
	int linenum;

	i = 0;
	linenum = 0;
	gnl->result = 1;
	gnl->fd = open("1.cub", O_RDONLY);
	if (gnl->fd != 3)
		file_err(1);
	while (gnl->result > 0)
	{
		gnl->result = get_next_line(gnl->fd, &gnl->line);
		if (linenum >= info->iflen)
		{
			ft_cstrncpy(info->map[i], gnl->line, ft_strlen(gnl->line));
			printf("%s\n", info->map[i]);
			i++;
		}
		linenum++;
		free(gnl->line);
	}
	if (close(gnl->fd) != 0)
		file_err(2);
}

void	alc_arr(t_info *info)
{
	int i;

	i = 0;
	info->map = calloc(info->rlen, sizeof(char *));
	if (info->map == 0)
		file_err(3);
	i = 0;
	while (i < info->rlen)
	{
		info->map[i] = malloc(sizeof(char) * info->clen + 1);
		if (info->map[i] == 0)
			arr_free(info->map);
		ft_memset(info->map[i], '0', (sizeof(char) * info->clen + 1));
		info->map[i][info->clen] = 0;
		i++;
	}
}
