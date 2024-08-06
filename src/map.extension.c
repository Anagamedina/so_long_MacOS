/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:25:47 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/06 14:13:31 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contiene funciones para leer y validar el archivo de mapa
#include "../includes/so_long.h"

/*t_game  *init(void)
{


}*/

int validate_file(char **argv)
{
    char    *file_extension;
    int     len_file_extension;
    int     len_argv;
    int     i;

    file_extension = ".ber";
    len_file_extension  = strlen(file_extension);
    len_argv = strlen(argv[1]);
    i = len_file_extension;
    while (i >= 0)
    {
        if (argv[1][len_argv] != file_extension[i])
            return (0);
        i--;
        len_argv--;
    }
    return (1);
}





/*int ft_open_map(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("fd < 0");
        exit(1);
    }
    return (fd);
}*/
