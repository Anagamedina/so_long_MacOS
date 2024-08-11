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
	{
		printf("fd < 0");
		exit(0);
	}
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

	fd = ft_open_map(path);
	i = 0;
	while (read(fd, &buffer, 1))
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
	read (fd, map1d, i);
//	printf("%s\n", map1d);
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

	i = 0;
	map1d = read_file(path);
	if (!map1d)
		return ;
	copy_map->matrix = ft_split(map1d, '\n');
	while (copy_map->matrix[i] != NULL)
		i++;
	copy_map->rows = i;
	if (!copy_map->matrix)
	{
		write(1, "error: Failed to split map\n", 27);
		free(map1d);
		return ;
	}
	line = (int) ft_strlen(copy_map->matrix[0]);
	copy_map->cols = line;
//	printf("line 0: %d\n", line);
	i = 1;
	while (copy_map->matrix[i] != NULL)
	{
		line = (int) ft_strlen(copy_map->matrix[i]);
//		printf("line %i: %d\n", i, line);
		if (copy_map->cols != line)
		{
			write(1, "error: Invalid map file\n", 24);
			exit(0);
		}
		i++;
	}
}