/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:33:16 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/11 13:51:09 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map2d(t_map *copy_map)
{
    int i;
    
    i = 0;
    if (copy_map->matrix != NULL)
    {
        while (i < copy_map->rows)
        {
            if (copy_map->matrix[i] != NULL)
            {
                free(copy_map->matrix[i]);
            }
            i++;
        }
        free(copy_map->matrix);
        free(copy_map);
    }
}

//Una funcion que tome como parametros size de la frase del error,
// la cadena donde guardar el error
//la instancia de la estructura 
void	handle_error(char *str, int size, t_map *copy_map)
{
    write(2, str, size);
    if(copy_map->matrix != NULL)
        free_map2d(copy_map);
    exit(EXIT_FAILURE);
}

void	handle_exit(char *str, int size)
{
    write(2, str, size);
    exit(EXIT_FAILURE);
}

void free_game(t_game *game)
{
    if (game)
    {
        if (game->map)
            free_map2d(game->map);  // Liberar la matriz 2D
        free(game);  // Liberar la estructura t_game
    }
}