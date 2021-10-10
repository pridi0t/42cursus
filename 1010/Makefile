# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 20:01:52 by hyojang           #+#    #+#              #
#    Updated: 2021/10/06 19:16:48 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
READLINE = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
IFLAG = -I
LIBFT_F = ./libft

LIBS = -lft
LIB_DIR = -L./libft -L.

RM = rm -f

FILES = minishell		\
		chk_builtins	\
		linkedlist1		\
		linkedlist2		\
		envp_func		\
		parsing_str		\
		ft_csplit		\
		builtin_func1	\
		builtin_func2	\
		builtin_echo	\
		builtin_cd		\
		exec_external	\
		minishell_utils

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) -c -o $@ $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_F)
	$(CC) $(CFLAGS) $(IFLAG)$(LIBFT_F) $(OBJS) $(LIB_DIR) $(LIBS) $(READLINE) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_F) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_F) fclean

re: clean all

.PHONY: all clean fclean re
