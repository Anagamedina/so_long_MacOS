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

//abrir el mapa y solo leerlo y le pasamos la ruta al archivo
//int fd = ft_open_map("ruta/al/archivo.ber");

//esta funcion es para inicializar la estructura de t_game especificamente t_map

t_game	*init_game(void)
{
	t_game	*game;
	t_map	*copy_map;

	game = malloc(sizeof(t_game));
	copy_map = malloc(sizeof (t_map));
	if (!game || !copy_map)
	{
		free(game);
		free(copy_map);
		return (NULL);
	}
	copy_map->matrix = NULL;
	copy_map->rows = 0;
	copy_map->columns = 0;
	copy_map->coins = 0;
	copy_map->exit = 0;
	copy_map->players = 0;
	copy_map->player.x = -1;
	copy_map->player.y = -1;
	game->map = copy_map;
	return (game);
}


//para abrir el mapa le pasamos como parametros la ruta pero y el mapa?
int	ft_open_map(char *path)
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

char	*read_file(char *path)
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
	copy_map->columns = line;
//	printf("line 0: %d\n", line);
	i = 1;
	while (copy_map->matrix[i] != NULL)
	{
		line = (int) ft_strlen(copy_map->matrix[i]);
//		printf("line %i: %d\n", i, line);
		if (copy_map->columns != line)
		{
			//TODO: HACER UNA FUNCION QUE LLAME A ERRROES Y LIBERE MEMORIA O RESETEE ESTRUCTURA
			write(1, "error: Invalid map file\n", 24);
			exit(0);
		}
		i++;
	}
}

int	check_first_and_last_line(t_map *copy_map)
{
	int	j;

	j = 0;
	while (copy_map->matrix[0][j] != '\0')
	{
		if (copy_map->matrix[0][j] != '1')
		{
			printf(" error no es 1 pared");
			return (0);
		}
		j++;
	}
	j = 0;
	while (copy_map->matrix[copy_map->rows - 1][j] != '\0')
	{
		if (copy_map->matrix[copy_map->rows - 1][j] != '1')
		{
			printf(" error no es 1 pared");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_laterals_map(t_map *copy_map)
{
	int	i;

	i = 0;
	while (i < copy_map->rows)
	{
		if (copy_map->matrix[i][0] != '1' || copy_map->matrix[i][copy_map->columns - 1] != '1')
		{
			printf(" error no es 1 pared");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < copy_map->rows)
	{
		if (copy_map->matrix[i][copy_map->columns - 1] != '1')
		{
			printf(" error no es 1 pared");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_validations(char *path, t_map *copy_map)
{
	if (validate_path(path) == 1)
	{
		printf("file is valid\n");
		read_map(path, copy_map);
		if (check_first_and_last_line(copy_map) == 1 && check_laterals_map(copy_map) == 1)
			printf("validacion mapa paredes correctas");
	}
	else
		printf("error file\n");
}
