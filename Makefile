# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2026/02/28 23:08:43 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	app.c \
		main.c \
		parse_input.c \

OBJ = 	app.o \
		main.o \
		parse_input.o \

HEADER = philo.h

# Libft
LIBFT_DIR = libs/Libft-2.2.1
LIBFT_HEADER_DIR = $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g -I$(LIBFT_HEADER_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Trigger Libft compilation
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all 
	--track-origins=yes ./$(NAME)

norm:
	norminette -R CheckForbiddenHeaderSource

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all valgrind norm re clean fclean
