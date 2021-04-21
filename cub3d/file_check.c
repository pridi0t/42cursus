/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:04:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/21 22:09:29 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	input_r(t_r *r, char *line)
{
	int i;

	i = 0;
	if (r->width != -1 && r->height != -1)
		return (1);
	ft_bzero(r, sizeof(int) * 2);
	while (line[i] == ' ')
		i++;
	r->width = simple_atoi(line, &i);
	while (line[i] == ' ')
		i++;
	r->height = simple_atoi(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		return (3);
	return (0);
}

int	input_rgb(t_rgb *rgb, char *line)
{
	int i;
	
	i = 0;
	if (rgb->r != -1 && rgb->g != -1 && rgb->b != -1)
		return (1);
	ft_bzero(rgb, sizeof(int) * 3);
	while (line[i] == ' ')
		i++;
	rgb->r = simple_atoi(line, &i);
	if (line[i++] != ',')
		return (2);
	rgb->g = simple_atoi(line, &i);
	if (line[i++] != ',')
		return (2);
	rgb->b = simple_atoi(line, &i);
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		return (3);
	if ((rgb-> r < 0 || rgb->r > 255) || (rgb-> g < 0 || rgb->g > 255) || (rgb-> b < 0 || rgb->b > 255))
		return (4);
	return (0);
}

int input_tex(char **tmp, char *line, int *i)
{
	int fd;
	char *tex;
	
	fd = 0;
	tex = ft_strtrim(&line[*i + 3], " ");
	*tmp = tex;
	if (ft_strncmp(&tex[ft_strlen(tex) - 4], ".xpm", 4) != 0)
	{
		free(tex);
		tex = 0;
		return (5);
	}
	fd = open(tex, O_RDONLY);
	if (fd == -1)
	{
		free(tex);
		tex = 0;
		return (6);
	}
	return (0);
}

int	input_info(t_info *info, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' && line[i] != 0)
		i++;
	if (line[i] == 'R' && ft_strlen(&line[i]) > 2 && line[i + 1] == ' ')
		return (print_error(input_r(&(info->r), ft_strtrim(&line[i + 2], " ")), "R"));
	else if (ft_strncmp(&line[i], "NO", 2) == 0 && ft_strlen(&line[i]) > 3 && line[i + 2] == ' ')
		return (print_error(input_tex(&(info->no), line, &i), "NO"));
	else if (ft_strncmp(&line[i], "SO", 2) == 0 && ft_strlen(&line[i]) > 3 && line[i + 2] == ' ')
		return (print_error(input_tex(&(info->so), line, &i), "SO"));
	else if (ft_strncmp(&line[i], "WE", 2) == 0 && ft_strlen(&line[i]) > 3 && line[i + 2] == ' ')
		return (print_error(input_tex(&(info->we), line, &i), "WE"));
	else if (ft_strncmp(&line[i], "EA", 2) == 0 && ft_strlen(&line[i]) > 3 && line[i + 2] == ' ')
		return (print_error(input_tex(&(info->ea), line, &i), "EA"));
	else if (line[i] == 'S' && ft_strlen(&line[i]) > 2 && line[i + 1] == ' ')
		return (print_error(input_tex(&(info->s), line, &i), "S"));
	else if ((line[i] == 'F') && ft_strlen(&line[i]) > 2 && line[i + 1] == ' ')
		return (print_error(input_rgb(&(info->f), ft_strtrim(&line[i + 2], " ")), "F"));
	else if ((line[i] == 'C') && ft_strlen(&line[i]) > 2 && line[i + 1] == ' ')
		return (print_error(input_rgb(&(info->c), ft_strtrim(&line[i + 2], " ")), "C"));
	return (0);
}