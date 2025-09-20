# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:11:22 by ilnassi           #+#    #+#              #
#    Updated: 2025/09/13 01:51:51 by ilnassi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_calloc.c \
      ft_split.c \
      ft_strjoin.c \
      ft_strlen.c \
      ft_substr.c \
      get_next_line.c \
      get_next_line_utils.c \
      ft_printf.c \
      ft_utils_nbr.c \
      ft_utils_world.c \
      ft_bzero.c \
      ft_strdup.c


OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
