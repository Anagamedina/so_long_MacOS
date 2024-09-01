/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:20:08 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/01 22:51:03 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
    {
        printf("Error initializing mlx.\n");
        free(game->mlx_ptr);
		exit (1);
    }

    game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->cols* TILE_SIZE, game->map->rows* TILE_SIZE, "Hello Ana! so_long");
    if (game->win_ptr == NULL)
    {
        printf("Error creating window.\n");
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
        exit(1);
    }
//	init_sprite(game);
}

void	new_image(t_game *game, void **image, char *path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		printf("Error: Couldn't find a sprite at path: %s\n", path);
		exit (1);
	}
}


void	put_image(t_game *game, void *image, int x,  int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

void	identify_images(t_game *game)
{
	int i, j;
	int x, y;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			x = j * TILE_SIZE;  // j representa las columnas
			y = i * TILE_SIZE;  // i representa las filas

			// Determina qué imagen poner dependiendo del contenido del mapa
			if (game->map->matrix[i][j] == WALL)
				put_image(game, game->wall.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == FLOOR)
				put_image(game, game->floor.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == EXIT)
				put_image(game, game->exit_closed.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == PLAYER)
				put_image(game, game->player_back.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == COINS)
				put_image(game, game->coin.xpm_ptr, x, y);

			j++;
		}
		i++;
	}
}

/*****************MAIN FUNCTION*******************/

void	init_sprite(t_game *game)
{
	new_image(game, &game->player_back.xpm_ptr, PLAYER_BACK_XPM);
	new_image(game, &game->exit_closed.xpm_ptr, OPEN_EXIT_XPM);
    new_image(game, &game->coin.xpm_ptr, COIN_XPM);
    new_image(game, &game->floor.xpm_ptr, FLOOR_XPM);
	new_image(game, &game->wall.xpm_ptr, WALL_XPM);
}
