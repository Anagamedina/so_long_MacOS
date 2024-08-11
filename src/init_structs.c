/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:07:52 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/11 14:07:57 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//abrir el mapa y solo leerlo y le pasamos la ruta al archivo
//int fd = ft_open_map("ruta/al/archivo.ber");

//esta funcion es para inicializar la estructura de t_game especificamente t_map

t_game	*init_game(void)
{
	t_game	*game;
	t_map	*copy_map;

	game = malloc(sizeof(t_game));
	copy_map = malloc(sizeof (t_map));
	if (!game || !copy_map)
	{
		free(game);
		free(copy_map);
		return (NULL);
	}
	copy_map->matrix = NULL;
	copy_map->rows = 0;
	copy_map->columns = 0;
	copy_map->coins = 0;
	copy_map->exit = 0;
	copy_map->players = 0;
	copy_map->player.x = -1;
	copy_map->player.y = -1;
	game->map = copy_map;
	return (game);
}

/*t_position	inti_positions(void)
{
	t_position	new_positions;

	new_positions.x = 0;
	new_positions.y = 0;
	return (new_positions);
}*/
