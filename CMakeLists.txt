cmake_minimum_required(VERSION 3.25.2)
project(so_long_anaa C)

set(CMAKE_C_STANDARD 11)

add_executable(so_long_anaa
        src/main.c
        src/map_init.c
        includes/so_long.h
        libft/libft.h
        libft/ft_strlen.c
        libft/ft_split.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        src/init_structs.c
        src/handle_errors.c
        src/init_players.c
        includes/macros.h
        src/map_extensions.c
        src/map_extensions.c
        src/map_items.c
        src/game.c
)
