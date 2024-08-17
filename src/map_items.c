/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:46:21 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/17 13:43:34 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	validations_items(t_map *copy_map)
{
	printf("Players: %d\n", copy_map->players);
	printf("Coins: %d\n", copy_map->coins);
	printf("Exit: %d\n", copy_map->exit);
	if (copy_map->coins < 1 || copy_map->exit != 1 || copy_map->players != 1)
		handle_error(ERROR_ITEMS, 20, copy_map, NULL);
	else
	{
		printf("Items ok\n");
	}
}


/************************VALIDATION MAIN **************************/

void	map_items(t_map *map)
{
	int	j;
	int	i;

	i = 1;
	while (i < map->rows - 1)
	{
		j = 1;
		while (j < map->cols - 1)
		{
			if (map->matrix[i][j] == 'P')
				map->players++;
			else if (map->matrix[i][j] == 'C')
				map->coins++;
			else if (map->matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	validations_items(map);
}