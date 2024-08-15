# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2024/07/23 16:38:43 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) #-g -fsanitize=address

#Directorios 
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
SO_LONG_H = includes/so_long.h

#Archivos fuente y objetos 
#OBJ-->contiene una lista de archivos objeto (.o) 
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/game.c \
		$(SRC_DIR)/map_extension.c \
		$(SRC_DIR)/map_items.c \
		$(SRC_DIR)/map_init.c \
		$(SRC_DIR)/init_structs.c \
		$(SRC_DIR)/handle_errors.c \
		$(SRC_DIR)/init_players.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#Librerias
LIBFT = $(LIBFT_DIR)/libft.a
MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
#MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#
#===============REGLAS===================#

all: $(LIBFT) $(MLX_DIR)/libmlx_Linux.a $(NAME)

#Compilacion del programa principal 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

#Compilacion de libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#Compilacion de MinilibX
#makemlx:
	#$(MAKE) -C $(MLX_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)

#Compilacion de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c  Makefile $(SO_LONG_H)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Creacion del directorio de objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#Reglas de limpieza
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ) 

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
