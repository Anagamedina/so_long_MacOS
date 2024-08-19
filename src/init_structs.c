/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:07:52 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/19 11:29:08 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/************************VALIDATION MAIN **************************/

t_game	*init_game(void)
{
	t_game	*game;
	t_map	*map;

	map = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	
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

	game->map = map;
	return (game);
}

