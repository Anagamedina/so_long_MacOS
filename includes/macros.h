/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:42:16 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/19 13:41:25 by anamedin         ###   ########.fr       */
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

#endif // ERROR_MACROS_H


#define WALL_XPM "assets/wall.xpm"
#define FLOOR_XPM "assets/floor.xpm"
#define COIN_XPM "assets/coin.xpm"
#define OPEN_EXIT_XPM "assets/open-exit.xpm"
#define PLAYER_BACK_XPM "assets/player_back.xpm"
