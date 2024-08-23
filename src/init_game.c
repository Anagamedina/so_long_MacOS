/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:20:08 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/23 23:00:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void init_images(t_game *game)
{
    game->map->player = 0;
    game->movements = 0;
}

static void init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
    {
        printf("Error initializing mlx.\n");
        free(game->mlx_ptr);
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

t_image new_image(void *mlx, char *path)
{
    t_image image;

    image.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &image.x, &image.y);
    if (!image.xpm_ptr)
    {
        printf("Error loading image: %s\n", path);
        exit(1);
    }
    return (image);
}

static void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

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
				put_image(game->mlx_ptr, game->wall.xpm_ptr, x, y);
			if (game->map->matrix[i][j] == FLOOR)
				put_image(game->mlx_ptr, game->floor.xpm_ptr, x, y);
			if (game->map->matrix[i][j] == EXIT)
				put_image(game->mlx_ptr, game->exit_closed.xpm_ptr, x, y);
			if (game->map->matrix[i][j] == PLAYER)
				put_image(game->mlx_ptr, game->player_front.xpm_ptr, x, y);
			if (game->map->matrix[i][j] == COINS)
				put_image(game->mlx_ptr, game->coin.xpm_ptr, x, y);
			j++;
		}
		i++;
	}
}

/*****************MAIN FUNCTION*******************/

void	init_sprite(t_game *game)
{
	void	*mlx;

    init_images(game);
    init_mlx(game);
    mlx = game->mlx_ptr;
    game->wall = new_image(mlx, WALL_XPM);
    game->coin = new_image(mlx, COIN_XPM);
    game->floor = new_image(mlx, FLOOR_XPM);
    game->exit_closed = new_image(mlx, OPEN_EXIT_XPM);
    game->player_back = new_image(mlx, PLAYER_BACK_XPM);
	identify_images(game);
}
