# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:45:31 by sbertali          #+#    #+#              #
#    Updated: 2021/05/06 21:28:34 by sbertali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = libmlx.a
LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = libft
MLX_PATH = minilibx-linux

MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
SRC_PATH = ./src/

INCLUDES = -I includes

CC = clang
FLAGS = -Wall -Wextra -Werror

SRC =	$(SRC_PATH)cub3d.c\
		$(SRC_PATH)bitmap.c\
		$(SRC_PATH)events.c\
		$(SRC_PATH)parsing_color.c\
		$(SRC_PATH)parsing_file.c\
		$(SRC_PATH)parsing_map.c\
		$(SRC_PATH)parsing.c\
		$(SRC_PATH)player.c\
		$(SRC_PATH)raycasting.c\
		$(SRC_PATH)raycasting2.c\
		$(SRC_PATH)sprites.c\
		$(SRC_PATH)sprites2.c\
		$(SRC_PATH)textures.c\
		$(SRC_PATH)utils.c\
		$(SRC_PATH)walls.c

OBJECTS = cub3d.o\
		bitmap.o\
		events.o\
		parsing_color.o\
		parsing_file.o\
		parsing_map.o\
		parsing.o\
		player.o\
		raycasting.o\
		raycasting2.o\
		sprites.o\
		sprites2.o\
		textures.o\
		utils.o\
		walls.o

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	@$(CC) $(FLAGS) -w -fsanitize=address -g -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJECTS): $(SRC_PATH) $(SRC)
	@$(CC) $(FLAGS) -g -c $(SRC)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS) $(NAME)

fclean:
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(OBJECTS) $(NAME)