/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:02:53 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/08 11:02:56 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			i++;
		}
		linenum++;
		free(gnl->line);
	}
	if (close(gnl->fd) != 0)
		file_err(2);
}

void	alc_2arr(t_info *info)
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
			arr_free(info, 3);
		ft_memset(info->map[i], '0', (sizeof(char) * info->clen + 1));
		info->map[i][info->clen] = 0;
		i++;
	}
}
