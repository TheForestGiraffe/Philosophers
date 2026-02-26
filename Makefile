# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2026/02/26 15:38:07 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 

SRC = 	forks.c \
		ft_strtol.c \
		get_time_ms.c \
		main.c \
		parse.c \
		philo_routine.c \
		philos.c 

OBJ = 	ft_strtol.o \
		get_time_ms.o \
		main.o \
		parse.o \
		philo_routine.o \
		philos.o

HEADER = main.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all 
	--track-origins=yes ./$(NAME)

norm:
	norminette -R CheckForbiddenHeaderSource

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all valgrind norm re clean fclean
