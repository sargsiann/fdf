/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:42:51 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/28 23:37:00 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char    *get_map_char(char *file)
{
    int     fd;
    char    *map;
    char    *tmp;
    
    map = NULL;
    fd = open(file, O_RDONLY);
    tmp = NULL;
    if (fd < 0)
        return (NULL);
    map = get_next_line(fd);
    while (map)
    {
        tmp = get_next_line(fd);
        if (!tmp)
            break;
        map = ft_gstrjoin(map, tmp,1,1);  
    }
    return (map);
}

char    **get_map(char *argv[])
{
    char    *map;
    char    **map_matrix;

    map = NULL;
    map_matrix = NULL;

    map = get_map_char(argv[1]);
    if (map != NULL)
    {
        map_matrix = ft_split(map, '\n');
        free(map);
        return (map_matrix);
    }
    free(map);
    return (NULL);
}