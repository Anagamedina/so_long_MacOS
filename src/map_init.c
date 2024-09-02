/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:36:41 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/02 14:12:45 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_exit(ERROR_OPEN_FILE, 26);
	return (fd);
}

static char	*read_file(char *path)
{
	int		fd;
	char	*map1d;
	char	buffer;
	int		i;
	ssize_t	bytes_read;

	fd = ft_open_map(path);
	i = 0;
	bytes_read = read(fd, &buffer, 1);
	while(bytes_read > 0)
		i++;
	//close (fd);
	if (i == 0)
		handle_exit(ERROR_OPEN_FILE, 26);
	map1d = (char *)malloc(i + 1);
	if (!map1d)
		handle_exit(ERROR_MEMORY, 35);
	fd = open(path, O_RDONLY);
	if (fd < 0)
        handle_exit("Error reopening file.\n", 22);
	bytes_read = read(fd, map1d, i);
	if (bytes_read < 0)
		handle_exit(ERROR_OPEN_FILE, 26);
	map1d[i] = '\0';
	close(fd);
	return (map1d);
}
/************************PRINCIPAL **************************/

void	read_map(char *path, t_map *map)
{
	char	*map1d;
	int		i;
	int		line;

	map1d = read_file(path);
	if (map1d == NULL)
		return ;
	map->matrix = ft_split(map1d, '\n');
	free(map1d);
	if (map->matrix == NULL)
		handle_exit(ERROR_MEMORY, 35);
	i = 0;
	while (map->matrix[i] != NULL)
		i++;
	map->rows = i;
	line = (int) ft_strlen(map->matrix[0]);
	map->cols = line;
	i = 0;
	while (map->matrix[i] != NULL)
	{
		line = (int) ft_strlen(map->matrix[i]);
		if (map->cols != line)
			handle_error(ERROR_INVALID_MAP, 30, map, NULL);
		i++;
	}
}