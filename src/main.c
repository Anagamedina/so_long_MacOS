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
    if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
    {
        printf("Pixel out of bounds: (%d, %d)\n", x, y);
        return;
    }

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


static void free_resources(void *mlx_ptr, void *win_ptr, t_data *image)
{
    if (image && image->img)
        mlx_destroy_image(mlx_ptr, image->img);
    if (win_ptr)
        mlx_destroy_window(mlx_ptr, win_ptr);
    if (mlx_ptr)
    {
        mlx_destroy_display(mlx_ptr);
        free(mlx_ptr);
    }
}

int main(int argc, char **argv)
{
    t_game  *game;
    t_data  image;
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
        free_resources(mlx_ptr, NULL, NULL); 
        return (1);
    }

    image.img = mlx_new_image(mlx_ptr, 1920, 1080);
    if (image.img == NULL)
    {
        printf("Error creating image.\n");
        free_resources(mlx_ptr, NULL, NULL);
        return (1);
    }

    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    if (image.addr == NULL)
    {
        printf("Error getting image data address.\n");
        free_resources(mlx_ptr, win_ptr, &image);
        return (1);
    }

    // Imprimir los valores para depuración
    printf("Bits per pixel: %d\n", image.bits_per_pixel);
    printf("Line length: %d\n", image.line_length);
    printf("Endian: %d\n", image.endian);
    // Dibujar un pixel rojo en la imagen
    my_mlx_pixel_put(&image, 960, 540, 0x00FF0000); // Color rojo

    // Poner la imagen en la ventana
    mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);

    // Entrar en el loop de eventos de MiniLibX
    mlx_loop(mlx_ptr);

    // Liberar recursos
    free_resources(mlx_ptr, win_ptr, &image);

    return (0);
}