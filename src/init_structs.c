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

/************************VALIDATION MAIN **************************/

t_game	*init_game(void)
{
	t_game	*game;
	t_map	*copy_map = NULL;

 	game = (t_game *) malloc(sizeof(t_game));
   	if (!game)
    {
		return (NULL);
    }

    // Asignar memoria para 'copy_map'
    copy_map = (t_map *)malloc(sizeof(t_map));
    if (!copy_map)
    {
		//free(game);  // Liberar la memoria de 'game' en caso de error
    	return (NULL);
    } 
	copy_map->matrix = NULL;
	copy_map->rows = 0;
	copy_map->cols = 0;
	copy_map->coins = 0;
	copy_map->exit = 0;
	copy_map->players = 0;
	copy_map->player_pos.x = 0; // como tendo que iniciarlo con -1 o 0?
	copy_map->player_pos.y = 0; // como tendo que iniciarlo con -1 o 0?
	game->map = copy_map;
	return (game);
}

