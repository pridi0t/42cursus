/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/16 10:53:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	convert_arr(char map[][MAP_SIZE], char *line)
{
	static int	i = 0;
	int			j;

	j = 0;
	while (line[j] != 0 && j < MAP_SIZE)
	{
		if (line[j] == ' ')
			map[i][j] = '0';
		else
			map[i][j] = line[j];
		j++;
	}
	i++;
}

void	map_print(char map[][MAP_SIZE])
{
	int i, j;

	for (i = 0; i < MAP_SIZE; i++)
	{
		for (j = 0 ; j < MAP_SIZE ; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}
*/

int tex_len(char *line)
{
	int start;
	int end;
	int len;

	start = 0;
	while (line[start] == ' ' && line[start] != 0)
		start++;
	end = start;
	while (line[end] != ' ' && line[end] != 0)
		end++;
	return (end - start);
}

void	valid(t_valid *v, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' && line[i] != 0)
		i++;
	if (ft_strnstr(&line[i], "NO", ft_strlen(&line[i])) == &line[i] && ft_strlen(&line[i]) > 2)
		v->no_len = tex_len(&line[i + 2]);
	else if (ft_strnstr(&line[i], "SO", ft_strlen(&line[i])) == &line[i] && ft_strlen(&line[i]) > 2)
		v->so_len = tex_len(&line[i + 2]);
	else if (ft_strnstr(&line[i], "WE", ft_strlen(&line[i])) == &line[i] && ft_strlen(&line[i]) > 2)
		v->we_len = tex_len(&line[i + 2]);
	else if (ft_strnstr(&line[i], "EA", ft_strlen(&line[i])) == &line[i] && ft_strlen(&line[i]) > 2)
		v->ea_len = tex_len(&line[i + 2]);
	else if (line[i] == 'S' && ft_strlen(&line[i]) > 1)
		v->s_len = tex_len(&line[i + 1]);
}

int	main(void)
{
	int		fd;
	int		result;
	char	*line;
	t_valid v;

	//ft_memset(&map, '0', sizeof(map));
	result = 1;
	fd = open("1.cub", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (line != 0)
			valid(&v, line);
		printf("%s\n", line);
		//convert_arr(map, line);
		free(line);
	}
	//map_print(map);
	printf("no_len : %d\n", v.no_len);
	printf("so_len : %d\n", v.so_len);
	printf("we_len : %d\n", v.we_len);
	printf("ea_len : %d\n", v.ea_len);
	printf("s_len : %d\n", v.s_len);

	return 0;
}
