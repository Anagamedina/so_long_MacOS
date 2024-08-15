/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:26:31 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/15 08:10:53 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "mlx/mlx.h"
//# include "so_long/so_long.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <strings.h>
# include <stdlib.h>
//# include <stddef.h>
# include <fcntl.h>
# include "macros.h"

/********Estructura para posiciones en 2D*****/
typedef struct s_position
{
  int           x; // Coordenada X
  int           y; // Coordenada Y
} t_position;

/********Estructura para gestionar imágenes****/
typedef struct s_image
{
  void       *xpm_ptr; // Puntero a la imagen (por ejemplo, en formato XPM)
  int        x;        // Coordenada X en la ventana
  int        y;        // Coordenada Y en la ventana
}		t_image;

/******* Estructura para el mapa del juego******/
typedef struct s_map
{
  char			**matrix;       // Mapa representado como una matriz de cadenas
  int			rows;        // Número de filas en el mapa
  int			cols;     // Número de columnas en el mapa
  int			coins;       // Número de monedas en el mapa
  int			exit;        // Número de salidas en el mapa
  int			players;     // Número de jugadores en el mapa
  t_position	player_pos;
  t_position 	exit_pos; // Posición del jugado exitr
}			t_map;

/********Estructura principal del juego****/
typedef struct s_game
{
  // void			*mlx_ptr;            // Puntero a la instancia de MiniLibX o similar
  // void			*win_ptr;            // Puntero a la ventana del juego
  // int			  movements;           // Contador de movimientos
  // int			  player_sprite;       // Identificador del sprite del jugador
  t_map			  *map;                 // Información del mapa
  //t_bool		map_alloc;           // Bandera para verificar si el mapa ha sido alocado
  // t_image		wall;                // Imagen para las paredes
  // t_image		floor;               // Imagen para el suelo
  // t_image		coins;               // Imagen para las monedas
  // t_image		open_exit;           // Imagen para la salida abierta
  // t_image		exit_closed;         // Imagen para la salida cerrada
  // t_image		player_front;        // Imagen del jugador mirando hacia adelante
  // t_image		player_left;         // Imagen del jugador mirando hacia la izquierda
  // t_image		player_right;        // Imagen del jugador mirando hacia la derecha
  // t_image		player_back;         // Imagen del jugador mirando hacia atrás
}			t_game;

t_game		*init_game(void);
void	    map_format_border_check(char *path, t_map *copy_map);
void      map_items(t_map *copy_map);
void      read_map(char *path, t_map *copy_map);
//void      validations_items(t_map *copy_map);
//void      flood_fill(t_map *copy_map, int x, int y, int *ccoins);
//void	    validation_player(t_map *copy_map, int *ccoins);
void      validation_player(t_map *copy_map, int *ccoins);


/********HANDLE ERROR AND FREE ****/
void	    handle_error(char *str, int size, t_map *copy_map, t_game *game);
void	    handle_exit(char *str, int size);
void      free_game(t_game *game);
void      free_map2d(t_map *copy_map);
#endif // GAME_H

