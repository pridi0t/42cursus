# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 20:01:05 by hyojang           #+#    #+#              #
#    Updated: 2021/05/20 18:55:44 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I
LIBFT_F = ./libft

LIBS = -lft
LIB_DIR = -L./libft -L.

RM = rm -f

FILES = 

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(OBJS) $(LIB_DIR) $(LIBS) -o

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_F) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_F) fclean

re: clean all

.PHONY: all clean fclean re
