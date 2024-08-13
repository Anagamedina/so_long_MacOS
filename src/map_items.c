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


void validations_items(t_map *copy_map)
{
    printf("Players: %d\n", copy_map->players);
    printf("Coins: %d\n", copy_map->coins);
    printf("Exit: %d\n", copy_map->exit);

    if (copy_map->coins > 1 || copy_map->exit != 1 || copy_map->players != 1)
    {
        printf("Items no correctos\n");
        free_map2d(copy_map);
        exit(EXIT_FAILURE);
    }
    else
        printf("Items ok\n");
}

void    flood_fill(t_map *copy_map, int x, int y, int *ccoins, int *eexit)
{
    if (x < 0 || y < 0 || x >= copy_map->rows || y >= copy_map->cols)
        return ;
    if (copy_map->matrix[x][y] == '1' || copy_map->matrix[x][y] == 'V')
        return ;
    copy_map->matrix[x][y] = 'V';
    if (copy_map->matrix[x][y] == 'C')
        (*ccoins)++;
    else if (copy_map->matrix[x][y] == 'E')
        (*eexit)++;

    flood_fill(copy_map, x + 1, y, ccoins, eexit);
    flood_fill(copy_map, y - 1, y, ccoins, eexit);
    flood_fill(copy_map, x, y + 1, ccoins, eexit);
    flood_fill(copy_map, x, y - 1, ccoins, eexit);

}

// void	check(t_game *game, t_game *copy)
// {
// 	if (game->coins != copy->ncoins || game->exit != copy->nexit)
// 		ft_exit("Error, Ureachable c/e", 1, game, 1);
// 	f_free(copy);
// 	free(copy);
// }



// static void	map_paths(t_so_long *sl, int y, int x)
// {
// 	if (sl->map[y][x] != '1' && sl->map[y][x] != 'o' \
// 			&& sl->map[y][x] != 'c' && sl->map[y][x] != 'e' \
// 			&& sl->map[y][x] != 'p')
// 	{
// 		if (sl->map[y][x] == 'P')
// 			sl->map[y][x] = 'p';
// 		else if (sl->map[y][x] == 'E')
// 		{
// 			sl->etmp++;
// 			sl->map[y][x] = 'e';
// 			return ;
// 		}
// 		else if (sl->map[y][x] == 'C')
// 		{
// 			sl->c_tmp1++;
// 			sl->map[y][x] = 'c';
// 		}
// 		else
// 			sl->map[y][x] = 'o';
// 		map_paths(sl, y, x + 1);
// 		map_paths(sl, y + 1, x);
// 		map_paths(sl, y, x - 1);
// 		map_paths(sl, y - 1, x);
// 	}
// }

/*-----------------MAIN VALIDATOR-----------------*/

// void	map_validator(t_so_long *sl)
// {
// 	map_borderline(sl);
// 	map_chars(sl);
// 	map_paths(sl, sl->y, sl->x);
// 	if (sl->c_cnt != sl->c_tmp1)
// 		handle_error(PRINT_ERR_11, 32, sl);
// 	if (sl->ecnt != sl->etmp)
// 		handle_error(PRINT_ERR_12, 25, sl);
// }
