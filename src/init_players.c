/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:13:35 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/15 14:02:17 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	players_init_pos(t_map *copy_map)
{
	int	y;
	int	x;

	y = 0;
	while (y < copy_map->rows)
	{
		x = 0;
		while (x < copy_map->cols)
		{
			if (copy_map->matrix[y][x] == 'P')
			{
				copy_map->player_pos.x = x;
				copy_map->player_pos.y = y;
			}
			if (copy_map->matrix[y][x] == 'E')
			{
				copy_map->exit_pos.x = x;	// Guardar la posición de la salida
				copy_map->exit_pos.y = y;
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

static void	print_map(t_map *copy_map)
{
	int	y;
	int	x;

	y = 0;
	while (y < copy_map->rows)
	{
		x = 0;
		while (x < copy_map->cols)
		{
			ft_putchar(copy_map->matrix[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}

static void	flood_fill(t_map *copy_map, int x, int y, int *ccoins)
{
	if (x < 0 || y < 0 || x >= copy_map->cols || y >= copy_map->rows)
		return ;
	if (copy_map->matrix[y][x] == '1' || copy_map->matrix[y][x] == 'V')
		return ;
	if (copy_map->matrix[y][x] == 'C')
		(*ccoins)++;
	copy_map->matrix[y][x] = 'V';

	print_map(copy_map);

	flood_fill(copy_map, x + 1, y, ccoins);
	flood_fill(copy_map, x - 1, y, ccoins);
	flood_fill(copy_map, x, y + 1, ccoins);
	flood_fill(copy_map, x, y - 1, ccoins);
}

/************************VALIDATION MAIN **************************/

void	validation_player(t_map *copy_map, int *ccoins)
{
	players_init_pos(copy_map);
	/*ccoins caminos posibles*/
	flood_fill(copy_map, copy_map->player_pos.x, copy_map->player_pos.y, ccoins);

	// que ccoins == cpy_map->coins
	// matrix[exit.y][exit.x] == 'V'
	if (*ccoins == copy_map->coins && \
		copy_map->matrix[copy_map->exit_pos.y][copy_map->exit_pos.x] == 'V')
	{
		printf("¡CCOINS OKAY y SALIDA OKAY\n");
	}
	else
		printf("IMCOMPLETE COINS OR INACCESIBLE EXIT\n");
}

/*void	validation_player(t_map *copy_map, int *ccoins)
{
    players_init_pos(copy_map);
    flood_fill(copy_map, copy_map->player_pos.x, \
                     copy_map->player_pos.y,ccoins); 

    if(copy_map->matrix[copy_map->player_pos.y][copy_map->player_pos.x] == 'E') 
    {
        if (go_exit(copy_map, ccoins) == 0)
            printf("GAME OVER: ccoins puntero: %d\n", *ccoins);
        else
            printf("Sigue jugando\n");

    }
}*/

// printf(" VALIDATION PLAYER()\n");
//     printf("Coins del mapa originales: %d\n", copy_map->coins);
//     printf("ccoins puntero: %d\n", *ccoins);