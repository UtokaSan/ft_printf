# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florianb <florianb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 02:35:43 by florianb          #+#    #+#              #
#    Updated: 2024/11/13 00:09:43 by florianb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
FLAGS_DIR = $(SRCS_DIR)/flags
HEADERS_DIR = include
LIBFT_DIR = lib/libft

# Récupérer tous les fichiers .c dans srcs et srcs/flags
SRCS = $(wildcard $(SRCS_DIR)/*.c) $(wildcard $(FLAGS_DIR)/*.c) main.c
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_DIR)

all: my_program

my_program: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o my_program $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f my_program

re: fclean all

.PHONY: all clean fclean re