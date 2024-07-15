/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:47:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/15 18:48:22 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static char	**get_2d_map(int fd)
{
	char	**map;
	char	*tmp;
	char	*tmp_map;

	tmp = NULL;
	tmp_map = ft_strdup("");
	map = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp_map = ft_gstrjoin(tmp_map, tmp, 1, 1);
	}
	map = ft_split(tmp_map, '\n', 1);
	return (map);
}

char	**get_map(char *filename)
{
	char	**map;
	int		fd;

	map = NULL;
	fd = open(filename, O_RDONLY);
	map = get_2d_map(fd);
	return (map);
}
