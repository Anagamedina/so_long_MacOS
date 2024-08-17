/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:31:54 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/18 01:06:15 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);*/
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
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
    // int     img_width;
    // int     img_height;
    // char    *relative_path = "./test.xpm";

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
        free_game(game); 
    }

    /***********Inicializar MiniLibX*************/
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        printf("Error initializing mlx.\n");
        return (1);
    }

    /**********Crear una nueva ventana*************/
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello Ana! so_long");
    if (win_ptr == NULL)
    {
        printf("Error creating window.\n");
        mlx_destroy_display(mlx_ptr);
        free_resources(mlx_ptr, NULL, NULL); 
        return (1);
    }

    /**********Cargar la imagen XPM *************/
    // image.img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
    if (image.img == NULL)
    {
        printf("Error loading XPM image.\n");
        free_resources(mlx_ptr, win_ptr, NULL);
        return (1);
    }
    /**********direccion memoria de imagen  *************/
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    if (image.addr == NULL)
    {
        printf("Error getting image data address.\n");
        free_resources(mlx_ptr, win_ptr, &image);
        return (1);
    }

    printf("Bits per pixel: %d\n", image.bits_per_pixel);
    printf("Line length: %d\n", image.line_length);
    printf("Endian: %d\n", image.endian);
    

    /****************Poner la imagen en la ventana********************/
    mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);

    /*****************loop de eventos de MiniLibX*******************/
    mlx_loop(mlx_ptr);
    free_resources(mlx_ptr, win_ptr, &image);
    return (0);
}




    //my_mlx_pixel_put(&image, 960, 540, 0x00FF0000);
    /************************************ */
    // image.img = mlx_new_image(mlx_ptr, 1920, 1080);
    // if (image.img == NULL)
    // {
    //     printf("Error creating image.\n");
    //     free_resources(mlx_ptr, NULL, NULL);
    //     return (1);
    // }

    