/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:46:21 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/11 21:46:27 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
//funcion que sirve para empezar en rectangulo pequeño 
//funcion para validar 1 0 P E C (ITEMS)


static void validations_items(t_map *copy_map)
{
    printf("Players: %d\n", copy_map->players);
    printf("Coins: %d\n", copy_map->coins);
    printf("Exit: %d\n", copy_map->exit);

    if (copy_map->coins < 1 || copy_map->exit != 1 || copy_map->players != 1)
    {
        printf("Items no correctos\n");
        free_map2d(copy_map);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Items ok\n");
    }
}


/************************VALIDATION MAIN **************************/

void    map_items(t_map *copy_map)
{
    int j;
    int i;

    i = 1;
    j = 1;
    while (i < copy_map->rows - 1)
    {
        j = 1;
        while (j < copy_map->cols - 1)
        {
            if (copy_map->matrix[i][j] == 'P')
                copy_map->players++;
            else if (copy_map->matrix[i][j] == 'C')
                copy_map->coins++;
            else if (copy_map->matrix[i][j] == 'E')
                copy_map->exit++;
            j++;
        }
        i++;
    }
    validations_items(copy_map);
}