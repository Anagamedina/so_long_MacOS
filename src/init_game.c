/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:20:08 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/19 13:54:57 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void init_images(t_game *game)
{
    game->map->players = 0;
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

    game->win_ptr = mlx_new_window(game->mlx_ptr, 500, 500, "Hello Ana! so_long");
    if (game->win_ptr == NULL)
    {
        printf("Error creating window.\n");
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
        exit(1);
    }
}

t_image new_sprite(void *mlx, char *path)
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

/*****************MAIN FUNCTION*******************/

void init_sprite(t_game *game)
{
    void *mlx;

    init_images(game);
    init_mlx(game);
    mlx = game->mlx_ptr;
    game->wall = new_sprite(mlx, WALL_XPM);
    game->coin = new_sprite(mlx, COIN_XPM);
    game->floor = new_sprite(mlx, FLOOR_XPM);
    game->exit_closed = new_sprite(mlx, OPEN_EXIT_XPM);
    game->player_back = new_sprite(mlx, PLAYER_BACK_XPM);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.xpm_ptr, 1, 1);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, 50, 50);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_closed.xpm_ptr, 300, 300);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_back.xpm_ptr, 150, 150);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coin.xpm_ptr, 250, 250);
}