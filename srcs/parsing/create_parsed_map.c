/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parsed_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:59:12 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 18:06:39 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

char	*create_parsed_map(char *file_name)
{
	char    *map;
	char    *tmp;
	int     fd;

	fd = open(file_name, O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		map = ft_gstrjoin(map, tmp, 1, 1);
	}
	return (map);
}
