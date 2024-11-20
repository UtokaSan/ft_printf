# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 02:35:43 by fboulbes          #+#    #+#              #
#    Updated: 2024/11/20 18:13:41 by fboulbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

NAME = libftprintf.a

SRCS_DIR = src
FLAGS_DIR = $(SRCS_DIR)/flags
HEADERS_DIR = include
LIBFT_DIR = lib/libft

SRCS = $(SRCS_DIR)/ft_printf.c \
       $(FLAGS_DIR)/ft_print_char.c \
       $(FLAGS_DIR)/ft_print_decimal.c \
       $(FLAGS_DIR)/ft_print_hex.c \
       $(FLAGS_DIR)/ft_print_percent.c \
       $(FLAGS_DIR)/ft_print_pointer.c \
       $(FLAGS_DIR)/ft_print_string.c \
       $(FLAGS_DIR)/ft_print_unsigned.c 

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

.PHONY: all clean fclean re $(MAIN)