/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:26:04 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/01 00:10:44 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
 * crear una funcion para mover el jugador usando el teclado
 * usando las macros
 *
 */
void	ft_close_game(t_game *game)
{
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);  // Cierra la ventana del juego

	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);  // Destruye el display (solo en Linux)
		free(game->mlx_ptr);  // Libera la memoria de la instancia de MLX
	}
	free(game->map->matrix);  // Ejemplo: libera la matriz del mapa
	free(game);  // Libera la estructura principal del juego
	exit(0);  // Salir del juego
}

void	ft_victory(t_game *game)
{
	printf("¡Felicidades! ¡Has ganado el juego en %d movimientos!\n", game->movements);
	ft_close_game(game);  // Llama a la función de cierre para salir del juego
}

void	move_player(t_game *game, int new_x, int new_y, int player_sprite)
{
	int	last_x;
	int last_y;

	last_x = game->map->player_pos.x;
	last_y = game->map->player_pos.y;

	if (new_x < 0 || new_x >= game->map->cols || new_y < 0 || new_y >= game->map->rows)
	{
		printf("Invalid move: new_x=%d, new_y=%d\n", new_x, new_y);
		return;
	}

	// Verifica si el movimiento es hacia una posición válida
	if (game->map->matrix[new_x][new_y] == WALL)
		return; // No hacer nada si es una pared

	game->player_sprite = player_sprite;

	// Verifica si el jugador alcanza la salida
	if (game->map->matrix[new_x][new_y] == EXIT && game->map->coins == 0)
	{
		ft_victory(game);
		return;
	}

	// Si el jugador se mueve a un suelo o recoge una moneda
	if (game->map->matrix[new_x][new_y] == FLOOR || game->map->matrix[new_x][new_y] == COINS)
	{
		// Actualiza la posición anterior del jugador a FLOOR
		game->map->matrix[last_x][last_y] = FLOOR;

		// Si recoge una moneda, decrementa el contador
		if (game->map->matrix[new_x][new_y] == COINS)
			game->map->coins--;
		printf("coins: %d\n", game->map->coins);
		// Actualiza la nueva posición del jugador
		game->map->player_pos.x = new_x;
		game->map->player_pos.y = new_y;
		game->map->matrix[new_x][new_y] = PLAYER;
		printf("Moving player to: new_x=%d, new_y=%d\n", new_x, new_y);

		// Incrementa el contador de movimientos
		game->movements++;
		printf("movimientos: %d\n", game->movements);

		// Renderiza el mapa actualizado
		identify_images(game);
	}
}
/*****************PRINCIPAL FUNCTION*******************/

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		move_player(game, game->map->player_pos.y - 1, game->map->player_pos.x, BACK);
	/*else if (keysym == KEY_A)
		move_player(game, game->map->player_pos.y, game->map->player_pos.x - 1, LEFT);
	*/
	else if (keysym == KEY_S)
		move_player(game, game->map->player_pos.y + 1, game->map->player_pos.x, FRONT);
	/*else if (keysym == KEY_D)
		move_player(game, game->map->player_pos.y, game->map->player_pos.x + 1, RIGHT);
	*/
	else if (keysym == KEY_ESC)
		ft_close_game(game);
	return (0);
}