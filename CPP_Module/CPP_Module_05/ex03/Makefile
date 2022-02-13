# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 13:39:27 by hyojang           #+#    #+#              #
#    Updated: 2022/02/13 15:54:05 by hyojang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

FILES = main					\
		Bureaucrat				\
		Form					\
		ShrubberyCreationform	\
		RobotomyRequestForm		\
		PresidentialPardonForm	\
		Intern

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
	$(RM) *shrubbery

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
