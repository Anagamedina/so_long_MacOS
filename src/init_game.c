/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:20:08 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/31 18:27:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
    {
        printf("Error initializing mlx.\n");
        free(game->mlx_ptr);
		exit (1);
    }

    game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->cols * TILE_SIZE, game->map->rows * TILE_SIZE, "Hello Ana! so_long");
    if (game->win_ptr == NULL)
    {
        printf("Error creating window.\n");
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
        exit(1);
    }
}

t_image	new_image(void *mlx, char *path)
{
	t_image	image;

	image.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &image.x, &image.y);
	if (image.xpm_ptr == NULL)
	{
		printf("Error: Couldn't find a sprite at path: %s\n", path);
		exit (1);
	}
	return (image);
}

static void	put_image(t_game *game, t_image image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image.xpm_ptr, x, y);
}

/*static void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}*/

void	identify_images(t_game *game)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while(j < game->map->cols)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (game->map->matrix[i][j] == WALL)
				put_image(game, game->wall, x, y);
			else if (game->map->matrix[i][j] == FLOOR)
				put_image(game, game->floor, x, y);
			else if (game->map->matrix[i][j] == EXIT)
				put_image(game, game->exit_closed, x, y);
			else if (game->map->matrix[i][j] == PLAYER)
				put_image(game, game->player_front, x, y);
			else if (game->map->matrix[i][j] == COINS)
				put_image(game, game->coin, x, y);
			j++;
		}
		i++;
	}
}

/*****************MAIN FUNCTION*******************/

void	init_sprite(t_game *game)
{
    init_mlx(game);
    game->wall = new_image(game->mlx_ptr, WALL_XPM);
    game->coin = new_image(game->mlx_ptr, COIN_XPM);
    game->floor = new_image(game->mlx_ptr, FLOOR_XPM);
    game->exit_closed = new_image(game->mlx_ptr, OPEN_EXIT_XPM);
    game->player_back = new_image(game->mlx_ptr, PLAYER_BACK_XPM);

	//identify_images(game);
}