# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 15:03:10 by hyojang           #+#    #+#              #
#    Updated: 2020/10/26 17:42:55 by hyojang          ###   ########.fr        #
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
				ft_split		\
				ft_itoa			\
				ft_strmapi		\
				ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd

BONUS_FILES = ft_lstnew			\
			  ft_lstadd_front	\
			  ft_lstsize		\
			  ft_lstlast		\
			  ft_lstadd_back	\
			  ft_lstdelone		\
			  ft_lstclear		\
			  ft_lstiter		\
			  ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus : $(OBJS_BONUS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
