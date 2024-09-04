/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:20:08 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/04 23:34:47 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf("Error initializing mlx.\n");
		free(game->mlx_ptr);
		exit (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->cols * TILE_SIZE, \
		game->map->rows * TILE_SIZE, "Hello Ana! so_long");
	if (game->win_ptr == NULL)
	{
		ft_printf("Error creating window.\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
}

void	new_image(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_printf("Error: Couldn't find a sprite at path: %s\n", path);
		exit (1);
	}
}

void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

void	render_player(t_game *game, int x, int y)
{
	if (game->player_sprite == BACK)
		put_image(game, game->player_back.xpm_ptr, x, y);
	else if (game->player_sprite == FRONT)
		put_image(game, game->player_front.xpm_ptr, x, y);
	else if (game->player_sprite == LEFT)
		put_image(game, game->player_left.xpm_ptr, x, y);
	else if (game->player_sprite == RIGHT)
		put_image(game, game->player_right.xpm_ptr, x, y);
}

void	identify_images(t_game *game, int i, int j)
{
	int	x;
	int	y;

	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (game->map->matrix[i][j] == WALL)
				put_image(game, game->wall.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == FLOOR)
				put_image(game, game->floor.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == EXIT)
				put_image(game, game->exit_closed.xpm_ptr, x, y);
			else if (game->map->matrix[i][j] == PLAYER)
			{
				put_image(game, game->player_front.xpm_ptr, x, y);
				render_player (game, x, y);
			}
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
	init_mlx(game);
	new_image(game, &game->player_front.xpm_ptr, PLAYER_FRONT_XPM);
	new_image(game, &game->player_back.xpm_ptr, PLAYER_BACK_XPM);
	new_image(game, &game->player_left.xpm_ptr, PLAYER_LEFT_XPM);
	new_image(game, &game->player_right.xpm_ptr, PLAYER_RIGHT_XPM);
	new_image(game, &game->exit_closed.xpm_ptr, OPEN_EXIT_XPM);
	new_image(game, &game->coin.xpm_ptr, COIN_XPM);
	new_image(game, &game->floor.xpm_ptr, FLOOR_XPM);
	new_image(game, &game->wall.xpm_ptr, WALL_XPM);
	identify_images(game, 0, 0);
}
