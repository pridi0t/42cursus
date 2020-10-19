# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 16:47:10 by jitlee            #+#    #+#              #
#    Updated: 2020/10/19 18:35:20 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES		= ft_memset \
			  	ft_bzero	\
				ft_memcpy	\
				ft_memccpy	\
				ft_memmove	\
				ft_memchr	\
				ft_memcmp	\
			  	ft_strlen	\
				ft_strlcpy	\
				ft_strlcat	\
				ft_strchr	\
				ft_strrchr	\
				ft_strnstr	\
				ft_strncmp	\
				ft_atoi		\
				ft_isalpha	\
				ft_isdigit	\
				ft_isalnum	\
				ft_isascii	\
				ft_isprint	\
				ft_toupper	\
				ft_tolower	\
				ft_calloc	\
				ft_strdup	\
				ft_substr	\
				ft_strjoin	\
				ft_strtrim	\
				ft_itoa

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
