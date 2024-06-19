/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_size_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:06:54 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 18:15:23 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	int get_row_size(char *row)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (row[i])
	{
		i++;
		if (ft_isdigit(row[i]) && (i - 1 == -1 || row[i - 1] == 32))
			size++;
	}
	return (size);
}

int	row_size_check(char **map)
{
	int i;
	int row_size;
	int tmp_row_size;

	row_size = get_row_size(map[0]);
	tmp_row_size = 0;
	i = 1;
	while (map[i])
	{
		tmp_row_size = get_row_size(map[i]);
		if (tmp_row_size != row_size)
			return (0);
		i++;
	}
	return (1);
}