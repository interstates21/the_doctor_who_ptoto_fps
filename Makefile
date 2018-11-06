#******************************************************************************#
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okupin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 01:43:55 by okupin            #+#    #+#              #
#    Updated: 2018/02/02 01:44:05 by okupin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = wolf3d.h

SRC =	main.c \
		linear.c \
		line.c \
		read.c \
		hsv.c \
		pixel.c \
		mlx.c \
		ft_map.c \
		count_map.c \
		raycasting.c \
		draw_lines.c \
		color_modes.c \
		control.c \
		additional.c \
		interface.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	/bin/rm -rf *.o
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re @(NAME)