# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 02:35:43 by fboulbes          #+#    #+#              #
#    Updated: 2025/01/27 20:53:02 by fboulbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

NAME = libftprintf.a

SRCS_DIR = src
HEADERS_DIR = include
LIBFT_DIR = lib/libft

SRCS = \
	src/ft_printf.c \
	src/flags/init_flags.c \
	src/flags/search_flags.c \
	src/flags/memory/print_pointer.c \
	src/flags/numbers/nbrlen.c \
	src/flags/numbers/print_decimal.c \
	src/flags/numbers/print_hex.c \
	src/flags/numbers/print_percent.c \
	src/flags/numbers/print_unsigned.c \
	src/flags/strings/print_char.c \
	src/flags/strings/print_string.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
