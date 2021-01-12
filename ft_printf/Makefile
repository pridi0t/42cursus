# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 10:32:40 by hyojang           #+#    #+#              #
#    Updated: 2021/01/12 12:18:32 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_atoi					\
		ft_itoa					\
		ft_itox					\
		ft_uitoa				\
		ft_printf				\
		ft_printf_parsing		\
		ft_printf_parsing_utils	\
		ft_printf_utils			\
		ft_printf_c				\
		ft_printf_s				\
		ft_printf_int

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
