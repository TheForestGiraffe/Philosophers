# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2026/02/28 21:48:53 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	app.c \
		ft_strtol.c \
		main.c \
		parse_input.c \

OBJ = 	app.o \
		ft_strtol.o \
		main.o \
		parse_input.o \

HEADER = philo.h

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
