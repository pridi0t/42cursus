# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 20:01:05 by hyojang           #+#    #+#              #
#    Updated: 2021/05/12 04:27:14 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I
LIBFT_F = ./libft

MLX = -lmlxc -lm -framework OpenGL -framework AppKit

LIBS = -lft
LIB_DIR = -L./libft -L.

RM = rm -f

FILES = cub3d				\
		get_next_line		\
		get_next_line_utils	\
		stack				\
		file_check1			\
		file_check2			\
		file_check_utils	\
		map_check			\
		map_convert			\
		map_utils			\
		ray					\
		wall_tex_ray1		\
		wall_tex_ray2		\
		sprite_tex_ray		\
		tex_ray_utils		\
		key

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(OBJS) $(LIB_DIR) $(LIBS) -o $(NAME) $(MLX) $(MLXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_F) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_F) fclean

re: clean all

.PHONY: all clean fclean re
