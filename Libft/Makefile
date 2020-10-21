# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 15:03:10 by hyojang           #+#    #+#              #
#    Updated: 2020/10/21 20:28:35 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES		= ft_memset \
			  	ft_bzero		\
				ft_memcpy		\
				ft_memccpy		\
				ft_memmove		\
				ft_memchr		\
				ft_memcmp		\
			  	ft_strlen		\
				ft_strlcpy		\
				ft_strlcat		\
				ft_strchr		\
				ft_strrchr		\
				ft_strnstr		\
				ft_strncmp		\
				ft_atoi			\
				ft_isalpha		\
				ft_isdigit		\
				ft_isalnum		\
				ft_isascii		\
				ft_isprint		\
				ft_toupper		\
				ft_tolower		\
				ft_calloc		\
				ft_strdup		\
				ft_substr		\
				ft_strjoin		\
				ft_strtrim		\
				ft_itoa			\
				ft_strmapi		\
				ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd

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
