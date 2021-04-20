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

typedef struct {
	int width;
	int height;
} t_r;

typedef struct {
	int r;
	int g;
	int b;
} t_rgb;

typedef struct {
	t_r		r;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	t_rgb	f;
	t_rgb	c;
} t_info;

typedef struct{
	int r_cnt;
	int no_len;
	int so_len;
	int we_len;
	int ea_len;
	int s_len;
	int f_cnt;
	int c_cnt;
} t_valid;
