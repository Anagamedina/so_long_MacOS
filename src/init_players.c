/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:13:35 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/03 18:11:10 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	players_init_pos(t_map *map)
{
	int	y;
	int	x;

	x = 1;
	while (x < map->rows)
	{
		y = 1;
		while (y < map->cols)
		{
			if (map->matrix[x][y] == 'P')
			{
				map->player_pos.y = y;
				map->player_pos.x = x;
			}
			if (map->matrix[x][y] == 'E')
			{
				map->exit_pos.y = y;
				map->exit_pos.x = x;
			}
			y++;
		}
		x++;
	}
}

void	flood_fill(t_map *map, int x, int y, int *ccoins)
{
	if (x < 0 || y < 0 || y >= map->cols || x >= map->rows)
		return ;
	if (map->matrix[x][y] == '1' || map->matrix[x][y] == 'V')
		return ;
	if (map->matrix[x][y] == 'C')
		(*ccoins)++;
	map->matrix[x][y] = 'V';
	flood_fill(map, x + 1, y, ccoins);
	flood_fill(map, x - 1, y, ccoins);
	flood_fill(map, x, y + 1, ccoins);
	flood_fill(map, x, y - 1, ccoins);
}

static void	copy_map_matrix(t_map *copy_map, t_map *map)
{
	int		i;
	int		j;

	copy_map->matrix = malloc(sizeof (char *) * map->rows);
	if (!copy_map->matrix)
		return ;
	i = 0;
	while (i < map->rows)
	{
		copy_map->matrix[i] = malloc(sizeof(char) * map->cols);
		if (!copy_map->matrix[i])
		{
			free_map2d(copy_map);
			return ;
		}
		j = 0;
		while (j < map->cols)
		{
			copy_map->matrix[i][j] = map->matrix[i][j];
			j++;
		}
		i++;
	}
}

/************************VALIDATION MAIN **************************/

void	validation_player(int *ccoins, t_map *map)
{
	t_map	copy_map;

	copy_map.rows = map->rows;
	copy_map.cols = map->cols;
	players_init_pos(map);
	copy_map_matrix(&copy_map, map);
	flood_fill(&copy_map, map->player_pos.x, map->player_pos.y, ccoins);
	if (*ccoins == map->coins || map->matrix[map->exit_pos.x][map->exit_pos.y] == 'V')
	{
		ft_printf("¡CCOINS Ok y Exit Ok\n");
	}
	else
		handle_error(ERROR_COINS_EXIT, 20, map, NULL);

	free_map2d(&copy_map);
	
}
