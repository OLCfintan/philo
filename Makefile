# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 20:51:04 by oel-mouk          #+#    #+#              #
#    Updated: 2024/12/13 20:51:05 by oel-mouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wextra -Werror -Wall -lpthread
RM = rm -rf
SRCS = $(shell find . -type f -name '*.c')
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	@echo "making is done :)"

$(OBJS): %.o: %.c
	@$(CC) $(FLAGS) -c $< -g $(THREAD) -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re : fclean
	@make
