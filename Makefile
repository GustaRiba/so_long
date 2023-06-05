# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 13:57:31 by gmorais-          #+#    #+#              #
#    Updated: 2023/06/02 14:04:00 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_NAME =	main.c \
			check_map.c \
			check_path.c \
			close_game.c \
			map.c \
			moves.c \
			get_next_line_utils.c \
			get_next_line.c \
			put_img.c \
			keys.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx -g -fsanitize=address
MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx -framework OpenGL -framework AppKit

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -I mlx_linux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -rf

HEADER = so_long.h

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

INC = -Iincludes -I/usr/include -Imlx_linux

SRC_PATH = ./src

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

all: $(NAME)

$(NAME) : $(libft) $(OBJS)
		make -s -C mlx_linux/
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make -C$(LIBFT_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(MLX_LIB)
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INC) $(MLX_INCLUDE)  $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re