/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:16:00 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/02 11:54:54 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void	print_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			ft_putchar(map->matrix[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}



/*
void	move_player(t_game *game, int new_x, int new_y, int player_sprite)
{
	int	last_x;
	int last_y;

	last_x = game->map->player_pos.x;
	last_y = game->map->player_pos.y;

	if (new_y < 0 || new_y >= game->map->cols || new_x < 0 || new_x >= game->map->rows)
	{
		ft_printf("Invalid move: new_x=%d, new_y=%d\n", new_x, new_y);
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
		ft_printf("coins: %d\n", game->map->coins);
		// Actualiza la nueva posición del jugador
		game->map->player_pos.x = new_x;
		game->map->player_pos.y = new_y;
		game->map->matrix[new_x][new_y] = PLAYER;
		ft_printf("Moving player to: new_x=%d, new_y=%d\n", new_x, new_y);

		// Incrementa el contador de movimientos
		game->movements++;
		ft_printf("movimientos: %d\n", game->movements);

		// Renderiza el mapa actualizado
		identify_images(game);
	}
}
*/