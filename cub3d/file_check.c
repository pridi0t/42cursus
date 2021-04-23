/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:04:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/23 10:47:22 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_r(t_r *r, char *line)
{
	int i;

	i = 1;
	if (r->width != -1 && r->height != -1)
		info_err(1, "R", line);
	if (!(ft_strlen(line) > 2 && line[1] == ' '))
		info_err(7, "R", line);
	while (line[i] == ' ')
		i++;
	r->width = simple_atoi(line, &i);
	while (line[i] == ' ')
		i++;
	r->height = simple_atoi(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		info_err(3, "R", line);
	if (r->width <= 0 || r->height <= 0)
		info_err(7, "R", line);
}

void	input_rgb(t_rgb *rgb, char *line, char *rgb_name)
{
	int i;

	i = 1;
	if (rgb->r != -1 && rgb->g != -1 && rgb->b != -1)
		info_err(1, rgb_name, line);
	if (!(ft_strlen(line) > 2 && line[1] == ' '))
		info_err(7, rgb_name, line);
	while (line[i] == ' ')
		i++;
	rgb->r = simple_atoi(line, &i);
	if (line[i++] != ',')
		info_err(2, rgb_name, line);
	rgb->g = simple_atoi(line, &i);
	if (line[i++] != ',')
		info_err(2, rgb_name, line);
	rgb->b = simple_atoi(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		info_err(3, rgb_name, line);
	if ((rgb->r < 0 || rgb->r > 255) || \
			(rgb->g < 0 || rgb->g > 255) || (rgb->b < 0 || rgb->b > 255))
		info_err(7, rgb_name, line);
}

void	input_tex(char **tmp, char *line, char *tex_name)
{
	int		fd;
	int		minlen;
	char	*tex;

	fd = 0;
	minlen = 3;
	tex = 0;
	if (*line == 'S' && ft_strncmp(line, "SO", 2) != 0)
		minlen = 2;
	if (!(ft_strlen(line) > minlen && line[minlen - 1] == ' '))
		info_err(7, tex_name, line);
	tex = ft_strtrim(&line[minlen], " ");
	*tmp = tex;
	if (ft_strncmp(&tex[ft_strlen(tex) - 4], ".xpm", 4) != 0)
		info_err(5, tex_name, line);
	fd = open(tex, O_RDONLY);
	if (fd == -1)
		info_err(6, tex_name, line);
}

void	input_info(t_info *info, char *line, t_mapinfo *minfo)
{
	char *str;

	if (*line == 'R')
		input_r(&(info->r), line);
	else if (ft_strncmp(line, "NO", 2) == 0)
		input_tex(&(info->no), line, "NO");
	else if (ft_strncmp(line, "SO", 2) == 0)
		input_tex(&(info->so), line, "SO");
	else if (ft_strncmp(line, "WE", 2) == 0)
		input_tex(&(info->we), line, "WE");
	else if (ft_strncmp(line, "EA", 2) == 0)
		input_tex(&(info->ea), line, "EA");
	else if (*line == 'S')
		input_tex(&(info->s), line, "S");
	else if (*line == 'F')
		input_rgb(&(info->f), line, "F");
	else if (*line == 'C')
		input_rgb(&(info->c), line, "C");
	else
	{
		if (minfo->maxlen < ft_strlen(line))
			minfo->maxlen = ft_strlen(line);
		(minfo->linenum)++;
	}
}
