/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:31:54 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/15 22:45:53 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contiene la función principal y la lógica de inicialización.
#include "../includes/so_long.h"
#include <stdio.h>

/*int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);*/
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (data == NULL || data->addr == NULL)
    {
        printf("Error: data or data->addr is NULL.\n");
        return;
    }

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
    t_game  *game;
    int     ccoins;
    void    *mlx_ptr;
    void    *win_ptr;

    // Inicializar puntero t_game
    game = NULL;
    ccoins = 0;

    if (argc != 2)
        handle_exit(ERROR_INVALID_ARG, 28);
    else
    {
        game = init_game();
        if (game != NULL)
        {
            map_format_border_check(argv[1], game->map);
            map_items(game->map);
            validation_player(&ccoins, game->map);
        }
        free_game(game);  // Esto libera `game`, `map`, e `image`
    }

    // Inicializar MiniLibX
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        printf("Error initializing mlx.\n");
        return (1);
    }

    // Crear una nueva ventana
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello Ana! so_long");
    if (win_ptr == NULL)
    {
        printf("Error creating window.\n");
        mlx_destroy_display(mlx_ptr);
        free(mlx_ptr);
        return (1);
    }

    // Asignar imagen a `game->image`
    // game->image->img = mlx_new_image(mlx_ptr, 1920, 1080);
    // if (game->image->img == NULL)
    // {
    //     printf("Error creating image.\n");
    //     free(mlx_ptr);
    //     return (1);
    // }

    game->image->addr = mlx_get_data_addr(game->image->img, &game->image->bits_per_pixel, &game->image->line_length, &game->image->endian);
    if (game->image->addr == NULL)
    {
        printf("Error getting image data address.\n");
        free(mlx_ptr);
        return (1);
    }

   // Renderizar texto en la ventana
    mlx_string_put(mlx_ptr, win_ptr, 50, 50, 0x00FF00, "Hello, MiniLibX!");

    // Dibujar un pixel en la imagen
    // my_mlx_pixel_put(game->image, 5, 5, 0x00FF0000);

    // Mostrar la imagen en la ventana
    // mlx_put_image_to_window(mlx_ptr, win_ptr, game->image->img, 0, 0);

    // Entrar en el loop de eventos de MiniLibX
    mlx_loop(mlx_ptr);

    // Liberar recursos (esto debería estar al final del programa)
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);

    return (0);
}

/*int	main(int argc, char **argv)
{
	t_game	*game;
    int		ccoins;
	void	*mlx_ptr;
	void	*win_ptr;
    t_data  *img;

	game = NULL;
    img = NULL;
	ccoins = 0;
	if (argc != 2)
		handle_exit(ERROR_INVALID_ARG, 28);
	else
	{
		game = init_game();
		if (game != NULL)
		{
			map_format_border_check(argv[1], game->map);
			map_items(game->map);
			validation_player(&ccoins, game->map);
		}
		free_game(game);
	}
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        printf("Error initializing mlx.\n");
        free(mlx_ptr);
        return (1);
    }
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello Ana! so_long");
    if (win_ptr == NULL)
    {
        printf("Error creating window.\n");
        return (free(mlx_ptr), 1);
    }
    img->img = mlx_new_image(mlx_ptr, 1920, 1080);
    if (img->img == NULL)
    {
        printf("Error creating image.\n");
        return (free(mlx_ptr), 1);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    if (img->addr == NULL)
    {
        printf("Error creating image.\n");
        return (free(mlx_ptr), 1);
    }
    my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);

    //mlx_destroy_window(mlx_ptr, win_ptr);
    //mlx_destroy_display(mlx_ptr);
    //free(mlx_ptr);
    //return (0);
    mlx_loop(mlx_ptr);
}*/
