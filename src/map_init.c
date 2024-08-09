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

    game = malloc(sizeof(t_game));
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

//estamos creando un puntero a una cadena donde vamos almacenar el archivo 
//el buffer no me queda claro cuanto seria el maximo 

char *read_file(char *path)
{
    int     fd;
    char    *map1d;
    char    buffer;
    int     i;

    fd = ft_open_map(path);
    if (fd == -1)
        write(1, "error: Invalid map file", 22);
    i = 0;
    while(read(fd, &buffer, 1)) //&& i < = max_width 
        i++;
    close (fd);

    if (i == 0)
    {
        write(1, "error: Empty file\n", 18);
        return (NULL);
    }
    map1d = (char *)malloc(i + 1);
    if (!map1d)
       write(1, "error: Memory allocation failed\n", 32); 
    fd = open(path, O_RDONLY);
    read =(fd, map1d, i);
    map1d[i] = '\0';
    close(fd);
    return(map1d);
}
//
//leemos el mapa con el path y sacamos copia del mapa 
//usamos la cadena donde esta el archivo 
//pasamos un puntero que apunta la instancia de la estructura de mapa (copia)
//linia es la medida de la primera fila de la matrix
//enotnces igualmos la linia a todas las filas de la matrix 
//pero cuando una linia no es igual deberia ser ERROR mapa NO valido 
void    read_map(char **path, t_map *copy_map)
{
    char    *map1d;
    int     i;
    int     line;

    validate_path(path);
    map1d = read_file(path);
    if (!map1d)
        return;
    //validate_map(map1d, copy_map);
    copy_map->matrix = ft_split(map1d, '\n');
    if (!copy_map->matrix)
        write(1, "error: Failed to split map\n", 27);
        free(map1d);
        return; 
    i = 0;
    line = ft_strlen(copy_map->matrix[i++]);
    copy_map->rows = line;
    while (copy_map->matrix[i])
    {
        if(copy_map->matrix[i] != line)
            write(1, "error: Invalid map file", 22);
        free(line);
        i++; 
    }
    copy_map->rows = i;
    copy_map->columns = line;
    //free de que...
}