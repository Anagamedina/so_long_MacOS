/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:07:52 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/17 11:30:14 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/************************VALIDATION MAIN **************************/

t_game	*init_game(void)
{
	t_game	*game;
	t_map	*map;
	t_data	*image;

	map = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	image = (t_data *)malloc(sizeof(t_data));
	if (!image)
	{
		return  (NULL);
	}
	map->matrix = NULL;
	map->rows = 0;
	map->cols = 0;
	map->coins = 0;
	map->exit = 0;
	map->players = 0;
	map->player_pos.x = -1;
	map->player_pos.y = -1;
	map->exit_pos.x = -1;
	map->exit_pos.y = -1;

	image->img = NULL;
    image->addr = NULL;
    image->bits_per_pixel = 0;
    image->line_length = 0;
    image->endian = 0;
    image->x = 0;
    image->y = 0;

	game->map = map;
	game->image = image;
	return (game);
}

