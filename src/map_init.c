/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:36:41 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/10 18:08:17 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//para abrir el mapa le pasamos como parametros la ruta pero y el mapa?
static int	ft_open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_exit(ERROR_OPEN_FILE, 26);
	
	return (fd);
}

//estamos creando un puntero a una cadena donde vamos almacenar el archivo 
//el buffer no me queda claro cuanto seria el maximo 

static char	*read_file(char *path)
{
	int		fd;
	char	*map1d;
	char	buffer;
	int		i;
	ssize_t	bytes_read;

	fd = ft_open_map(path);
	i = 0;
	while ((bytes_read = read(fd, &buffer, 1)) > 0)
		i++;
	close (fd);

	if (i == 0)
		handle_exit(ERROR_OPEN_FILE, 26);	
	map1d = (char *)malloc(i + 1);
	if (!map1d)
	{
		//return (NULL);
		//free(map1d);
		handle_exit(ERROR_MEMORY, 35);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
    {
        // free(map1d);
        handle_exit("Error reopening file.\n", 22);
    }

	bytes_read = read(fd, map1d, i);
	if (bytes_read < 0) 
	{
		// free(map1d);
		// close(fd);
		handle_exit(ERROR_OPEN_FILE, 26);
	}	
	map1d[i] = '\0';
	close(fd);
	return (map1d);
}
//
//leemos el mapa con el path y sacamos copia del mapa 
//usamos la cadena donde esta el archivo 
//pasamos un puntero que apunta la instancia de la estructura de mapa (copia)
//linia es la medida de la primera fila de la matrix
//enotnces igualmos la linia a todas las filas de la matrix 
//pero cuando una linia no es igual deberia ser ERROR mapa NO valido

void	read_map(char *path, t_map *copy_map)
{
	char	*map1d;
	int		i;
	int		line;

	map1d = read_file(path);
	if (map1d == NULL)
	 	return ;
	copy_map->matrix = ft_split(map1d, '\n');
	free(map1d);

	if (copy_map->matrix == NULL)
		handle_exit(ERROR_MEMORY, 35);

	i = 0;
	while (copy_map->matrix[i] != NULL)
		i++;
	copy_map->rows = i;

	line = (int) ft_strlen(copy_map->matrix[0]);
	copy_map->cols = line;
	i = 0;
	while (copy_map->matrix[i] != NULL)
	{
		line = (int) ft_strlen(copy_map->matrix[i]);
		if (copy_map->cols != line)
			handle_error(ERROR_INVALID_MAP, 23, copy_map, NULL);	
		i++;
	}
}