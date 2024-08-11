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

void    map_items(t_map *copy_map)
{
    int i;
    int j;

    i = 1;
    j = 1;
    while (i < copy_map->rows - 2)
    {
        j = 1;
        while (j < copy_map->cols - 2)
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

void validations_items(t_map *copy_map)
{
    if (copy_map->coins = 0 || copy_map->exit != 1 || copy_map->players != 1)
        printf("items no correctos\n");
        exit(EXIT_FAILURE);


}