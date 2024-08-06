/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:12:30 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/06 15:40:20 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//abrir el mapa y solo leerlo y le pasamos la ruta al archivo
//int fd = ft_open_map("ruta/al/archivo.ber");

//esta funcion es para inicializar la estructura de t_game especificamente t_map  
t_game  init(void)
{
    t_game  *game;

    game = malloc(sizeof(t_map));
    if (game)
    return (NULL);

    //game->mlx_ptr = NULL;
    //game->win_ptr = NULL;
    //game->player_sprite = 0;
    game->map.matrix = NULL;
    game->map.rows = 0;
    game->map.columns = 0;
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.player = 0;
    game->map.player.x = -1;
    game->map.player.y = -1;
    game->map_alloc = 0;
    return (game);
}


//para abrir el mapa le pasamos como parametros la ruta pero y el mapa?
int ft_open_map(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("fd < 0");
        exit(0);
    }
    return (fd);
}

//para leer el rchivo linia por linia y lo va almacenar en una matrix
void read_map(char *path)
{
    int     fd;
    char    *line;
    int     result;

    fd = ft_open_map(path);
    while ((result = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    if (result == 0)
    {
        printf("%s\n", line);
        free(line);
    }
    else if (result == -1)
    {
        printf("fd < 0");
    }
    close(fd);
}



/*

int	add_line_map(t_game *game, char *line)
{
	size_t	line_len;
	char	**new_grid;

	line_len = ft_strlen(line);
	if (game->height == 0)
		game->length = line_len;
	new_grid = my_realloc(game->mat, (game->height + 1) * sizeof(char *));
	if (new_grid == NULL)
		return (0);
	game->mat = new_grid;
	game->mat[game->height] = malloc(line_len + 1);
	if (game->mat[game->height] == NULL)
		return (0);
	ft_strcpy(game->mat[game->height], line);
	game->height++;
	return (1);
}
*/