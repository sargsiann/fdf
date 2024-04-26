/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:08:55 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 21:09:02 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

char	**create_map_matrix(char *map)
{
	char    **matrix;

	matrix = ft_split(map, '\n');
	if (!matrix)
		return (NULL);
	return (matrix);
}