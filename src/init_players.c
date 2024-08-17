/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:13:35 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/17 12:23:15 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	players_init_pos(t_map *map)
{
	int	y;
	int	x;

	y = 1;
	while (y < map->rows)
	{
		x = 1;
		while (x < map->cols)
		{
			if (map->matrix[y][x] == 'P')
			{
				map->player_pos.y = y;
				map->player_pos.x = x;
				printf("Players INIT: (%d, %d)\n", map->player_pos.y, map->player_pos.x);
			}
			if (map->matrix[y][x] == 'E')
			{
				map->exit_pos.y = y;
				map->exit_pos.x = x;
				printf("Exit INIT: (%d, %d)\n", map->exit_pos.y, map->exit_pos.x);
			}
			x++;
		}
		y++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	print_map(t_map *map)
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

static void	flood_fill(t_map *map, int x, int y, int *ccoins)
{
	if (x < 0 || y < 0 || x >= map->cols || y >= map->rows)
		return ;
	if (map->matrix[y][x] == '1' || map->matrix[y][x] == 'V')
		return ;
	if (map->matrix[y][x] == 'C')
		(*ccoins)++;
	map->matrix[y][x] = 'V';

	//print_map(map);

	flood_fill(map, x + 1, y, ccoins);
	flood_fill(map, x - 1, y, ccoins);
	flood_fill(map, x, y + 1, ccoins);
	flood_fill(map, x, y - 1, ccoins);
}
static void copy_map_matrix(t_map *copy_map, t_map *map)
{
	int		i;
	int		j;

	copy_map->matrix = malloc(sizeof (char *) * map->rows);
	if (!copy_map->matrix)
		return ;
	j = 0;
	while (j < map->rows)
	{
		copy_map->matrix[j] = malloc(sizeof(char) * map->cols);
		if (!copy_map->matrix[j])
		{
			i = 0;
			while (i < j)
			{
				free(copy_map->matrix[i]);
				i++;
			}
			free(copy_map->matrix);
			return ;
		}
		i = 0;
		while (i < map->cols)
		{
			copy_map->matrix[j][i] = map->matrix[j][i];
			i++;
		}
		j++;
	}
}


/************************VALIDATION MAIN **************************/

void	validation_player(int *ccoins, t_map *map)
{
	t_map	copy_map;

	copy_map.rows = map->rows;
	copy_map.cols = map->cols;
	players_init_pos(map);
	print_map(&map->matrix);
	copy_map_matrix(&copy_map, &map->matrix);
	flood_fill(&copy_map, map->player_pos.y, map->player_pos.x, ccoins);
	printf("Players final: (%d, %d)\n", map->player_pos.y, map->player_pos.x);
	printf("Exit final: (%d, %d)\n", map->exit_pos.y, map->exit_pos.x);

	if (*ccoins == map->coins || \
		map->matrix[map->exit_pos.y][map->exit_pos.x] == 'V')
	{
		printf("¡CCOINS OKAY y SALIDA OKAY\n");
	}
	else
		printf("IMCOMPLETE COINS %d: OR INACCESIBLE EXIT\n (%d, %d):", *ccoins, map->exit_pos.y, map->exit_pos.x)
		;
}