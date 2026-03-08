# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2026/03/09 00:25:54 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	app_create.c \
		app_destroy.c \
		app_get_and_set.c \
		main.c \
		parse_input.c \
		philo_eat.c \
		philo_sleep.c \
		philo_think.c \
		philo_get_and_set.c \
		run_dinner_simulation.c \
		run_monitor_thread.c \
		run_philo_thread.c \
		thread_safe_printf.c \
		time_utils.c \
		ft_strtol.c

OBJ = 	app_create.o \
		app_destroy.o \
		app_get_and_set.o \
		main.o \
		parse_input.o \
		philo_eat.o \
		philo_sleep.o \
		philo_think.o \
		philo_get_and_set.o \
		run_dinner_simulation.o \
		run_monitor_thread.o \
		run_philo_thread.o \
		thread_safe_printf.o \
		time_utils.o \
		ft_strtol.o

HEADER = philo.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

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
