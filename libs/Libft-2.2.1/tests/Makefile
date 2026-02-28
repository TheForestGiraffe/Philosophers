# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 13:15:08 by pecavalc          #+#    #+#              #
#    Updated: 2025/11/03 15:33:27 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_libft

GNL_BUFFER_SIZE = 100
	
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = test_ft_atoi.c test_ft_bzero.c test_ft_strtol.c \
	   test_ft_calloc_overflow.c test_ft_calloc.c test_ft_isalnum.c \
	   test_ft_isalpha.c test_ft_isascii.c test_ft_isdigit.c \
	   test_ft_isprint.c test_ft_itoa.c test_ft_memchr.c test_ft_memcmp.c \
	   test_ft_memcpy.c test_ft_memmove_backwardcpy.c test_ft_memmove_forwardcpy.c \
	   test_ft_memset.c test_ft_printf.c test_ft_putchar_fd.c test_ft_putendl_fd.c \
	   test_ft_putnbr_fd.c test_ft_split.c test_ft_putstr_fd.c test_ft_strchr.c \
	   test_ft_striteri.c test_ft_strjoin.c test_ft_strlcat.c test_ft_strlcpy.c \
	   test_ft_strlen.c test_ft_strmapi.c test_ft_strncmp.c test_ft_strnstr.c \
	   test_ft_strrchr.c test_ft_strtrim.c test_ft_substr.c test_ft_tolower.c \
	   test_ft_toupper.c test_get_next_line.c test_libft.c test_ft_strdup.c \
	   test_ft_swap.c

OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

LIBFT_DIR = ..
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS_DIR = $(LIBFT_DIR)/srcs
LIBFT_HEADER_DIR = $(LIBFT_DIR)/include
LIBFT_HEADER = $(LIBFT_HEADER_DIR)/libft.h

CFLAGS = -Wall -Wextra -Werror -g -I$(SRCS_DIR) -I$(LIBFT_HEADER_DIR) \
		 -D BUFFER_SIZE=$(GNL_BUFFER_SIZE)

all: $(NAME) test

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(LIBFT_HEADER)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c -g $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

norm:
	@echo "Verifying norm compliance...\n"
	norminette $^ -R CheckForbiddenHeaderSource $(LIBFT_HEADER_DIR)
	norminette $^ -R CheckForbiddenHeaderSource $(LIBFT_SRCS_DIR)

test: $(NAME)
	./$(NAME)
	
.PHONY: clean fclean re

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	rm -f _test_ft_putchar_fd_test.txt
	rm -f _test_ft_putendl_fd_test.txt
	rm -f _test_ft_putstr_fd_test.txt
	rm -f _test_ft_putnbr_fd_test.txt
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all