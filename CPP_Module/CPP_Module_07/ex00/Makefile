# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 13:39:27 by hyojang           #+#    #+#              #
#    Updated: 2022/02/15 13:55:26 by marvin           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = TEMPLATES

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
