# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 20:01:05 by hyojang           #+#    #+#              #
#    Updated: 2021/07/26 11:19:03 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAG = -I
LIBFT_F = ./libft

LIBS = -lft
LIB_DIR = -L./libft

RM = rm -f
	
.c.o: $(NAME).c $(NAME2).c
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $@ $<

all: $(NAME) $(NAME2)

$(NAME): $(NAME).o
	make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(NAME).o $(LIB_DIR) $(LIBS) -o $(NAME)

$(NAME2): $(NAME2).o
	make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(NAME2).o $(LIB_DIR) $(LIBS) -o $(NAME2)

clean:
	$(RM) $(NAME).o $(NAME2).o
	make -C $(LIBFT_F) clean

fclean: clean
	$(RM) $(NAME) $(NAME2)
	make -C $(LIBFT_F) fclean

re: clean all

.PHONY: all clean fclean re
