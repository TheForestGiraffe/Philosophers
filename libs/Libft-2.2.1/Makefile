# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 13:15:08 by pecavalc          #+#    #+#              #
#    Updated: 2025/11/03 15:29:36 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs
SRCS_DIR_GNL = $(SRCS_DIR)/get_next_line
SRCS_DIR_PRINTF = $(SRCS_DIR)/ft_printf

OBJS_DIR = objs

SRCS =  $(addprefix $(SRCS_DIR)/, ft_atoi.c ft_bzero.c ft_calloc.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c ft_lstadd_back.c ft_strtol.c \
		ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_swap.c)

SRCS_GNL = $(addprefix $(SRCS_DIR_GNL)/, get_next_line.c get_next_line_utils.c)

SRCS_PRINTF = $(addprefix $(SRCS_DIR_PRINTF)/, ft_printf.c convert_arg.c \
			  prefix_and_print_ptr.c print_char.c print_hex_lowcase_nbr.c \
			  print_hex_uppercase_nbr.c print_nbr.c print_str.c \
			  print_unsigned_nbr.c)

SRCS_ALL = $(SRCS) $(SRCS_GNL) $(SRCS_PRINTF)

OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(notdir $(SRCS_ALL)))

HEADER_DIR_PUBLIC = include
HEADER_DIR_GNL = srcs/get_next_line
HEADER_DIR_PRINTF = srcs/ft_printf

HEADER_PUBLIC = $(HEADER_DIR_PUBLIC)/libft.h
HEADER_GNL = $(HEADER_DIR_GNL)/get_next_line.h
HEADER_PRINTF = $(HEADER_DIR_PRINTF)/ft_printf.h

CFLAGS = -Wall -Wextra -Werror -c -I$(HEADER_DIR_PUBLIC) \
								  -I$(HEADER_DIR_GNL) \
								  -I$(HEADER_DIR_PRINTF)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

vpath %.c $(SRCS_DIR) $(SRCS_DIR_GNL) $(SRCS_DIR_PRINTF)

$(OBJS_DIR)/%.o: %.c $(HEADER_PUBLIC) $(HEADER_PRINTF) $(HEADER_GNL)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all