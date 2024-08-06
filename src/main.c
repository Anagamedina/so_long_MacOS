/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:25:28 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/06 14:05:36 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contiene la función principal y la lógica de inicialización.
#include "../includes/so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_game  *game; 
    void    *mlx_ptr;
    void    *win_ptr;

    if (argc != 2)
    {
        printf("Error\n");
    }
    else
    {
        if (validate_file(argv))
            printf("valid map\n");
        else
            printf("error map\n");
    }
}


    /*mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        ft_putstr("Error initializing mlx.\n");
        return (1);
    }
    free(mlx_ptr);
    return (0);

    win_ptr = mlx_new_window(mlx_ptr, 640, 480, "so_long");
    if (win_ptr == NULL)
    {
        ft_putstr("Error creating window.\n");
        return (free(mlx_ptr), 1);
    }
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
    return (0);
    //mlx_loop(mlx);
}*/
