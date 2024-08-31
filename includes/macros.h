/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:42:16 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/31 23:12:52 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MACROS_H
#define ERROR_MACROS_H

/*--------------------Error and free------------------*/
#define ERROR_INVALID_MAP "error\nInvalid map file\n"
#define ERROR_MEMORY_ALLOCATION "error: Memory allocation failed\n"
#define ERROR_INVALID_ARG "Error\nInvalid argument.\n"
#define ERROR_WALLS "Error\nInvalid walls in map.\n"
#define ERROR_COINS_EXIT "Error\nInvalid game\n"
#define ERROR_ITEMS "Error\nInvalid items\n"

/*--------------------Error and exit------------------*/
#define ERROR_OPEN_FILE "Error\nFailure to open arg-file.\n"
#define ERROR_MEMORY "Error\nMemory allocation failure.\n"

/*-------------------- ITEMS ASSIGN ------------------*/
#define WALL '1'
#define FLOOR '0'
#define COINS 'C'
#define EXIT 'E'
#define PLAYER 'P'

// Direcciones del jugador
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define BACK 2
#define FRONT 3

/*-------------------- SIZE OF SPRITE ------------------*/
#define TILE_SIZE 32

/*-------------------- XPM PATHS ------------------*/
#ifdef __APPLE__
# define PLAYER_BACK_XPM "/Users/catalinaburgos/Documents/42/so_long_ana/assets/player_back.xpm"
# define COIN_XPM "/Users/catalinaburgos/Documents/42/so_long_ana/assets/coin.xpm"
# define FLOOR_XPM "/Users/catalinaburgos/Documents/42/so_long_ana/assets/floor.xpm"
# define WALL_XPM "/Users/catalinaburgos/Documents/42/so_long_ana/assets/wall.xpm"
# define EXIT_CLOSED_XPM "/Users/catalinaburgos/Documents/42/so_long_ana/assets/exit-closed.xpm"
# define OPEN_EXIT_XPM "/Users/catalinaburgos/Documents/42/so_long_ana/assets/open-exit.xpm"
#else
# define PLAYER_BACK_XPM "../assets/player_back.xpm"
    # define COIN_XPM "../assets/coin.xpm"
    # define FLOOR_XPM "../assets/floor.xpm"
    # define WALL_XPM "../assets/wall.xpm"
    # define EXIT_CLOSED_XPM "../assets/exit-closed.xpm"
    # define OPEN_EXIT_XPM "../assets/open-exit.xpm"
#endif

/*-------------------- KEYS EVENTS ------------------*/
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#ifdef __APPLE__
#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#else
#define KEY_ESC 65307
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#endif

#endif
