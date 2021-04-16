/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:52:28 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/16 10:52:56 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "stack.h"
#include "libft.h"
#define MAP_SIZE 50

typedef struct {
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
} t_tex;

typedef struct {
	int r;
	int g;
	int b;
} t_rgb;

typedef struct {
	int width;
	int height;
} t_r;

typedef		struct{
	t_tex	*tex;
	t_rgb	*rgb;
	t_r		*r;
} info;
