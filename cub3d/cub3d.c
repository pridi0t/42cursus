/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/23 11:25:42 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_minfo(t_mapinfo *minfo)
{
	minfo->linenum = 0;
	minfo->maxlen = 0;
	(minfo->src).r = 0;
	(minfo->src).c = 0;
}

void file_err(int errno)
{
	if (errno == 1)
		perror("Error\nFile open error");
	else if (errno == 2)
		perror("Error\nFile close error");
	exit(1);
}

int	main(void)
{
	int			cnt;
	int			fd;
	int			result;
	char		*line;
	t_info		info;
	t_mapinfo	minfo;

	//ft_memset(&map, '0', sizeof(map));
	init_info(&info);
	init_minfo(&minfo);
	result = 1;
	fd = open("1.cub", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (ft_strlen(line) != 0)
			input_info(&info, line, &minfo);
		//printf("%s\n", line);
		//convert_arr(map, line);
		free(line);
	}
	if (close(fd) != 0)
		file_err(2);

	printf("R : %d %d\n", info.r.width, info.r.height);
	printf("NO : %s\n", info.no);
	printf("SO : %s\n", info.so);
	printf("WE : %s\n", info.we);
	printf("EA : %s\n", info.ea);
	printf("S : %s\n", info.s);
	printf("F : %d %d %d\n", info.f.r, info.f.g, info.f.b);
	printf("C : %d %d %d\n", info.c.r, info.c.g, info.c.b);
	printf("linenum : %d\n", minfo.linenum);
	printf("maxlen : %d\n", minfo.maxlen);

	// 2차원 배열 동적할당

	result = 1;
	cnt = 0;
	fd = open("1.cub", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (cnt > linenum)
		{

		}
		free(line);
	}
	return (0);
}
