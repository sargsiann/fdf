/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertical_neighbour.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:05:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/05/03 17:33:40 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	find_negihbour_index(int point_num, char **map, int	i)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (map[i][j])
	{
		if (map[i][j] == '-' || ft_isdigit(map[i][j]) 
			&& (j - 1 < 0 || map[i][j - 1] == 32))
		{
			flag++;
			if (flag == point_num)
				return (j);
		}
		j++;
	}
	return (-1);
}	

int	get_vertical_n(t_data *data, t_point *point, t_line *line)
{
	int	y_tmp;
	int	x_tmp;

	if (data->map[point->y + 1] == NULL)
		return (-1);
	y_tmp = point->y + 1;
	line->x2 = point->x;
	line->y2 = point->y + DEF_DISTANCE;
	x_tmp = find_negihbour_index(point->point_num, data->map, y_tmp);
	line->height1 = ft_atoi(point->line + x_tmp);
	x_tmp += move(point->line + x_tmp);
	if (point->line[x_tmp] == ',')
	{
		x_tmp += 2;
		line->color2 = ft_hex_to_dec(point->line + x_tmp);
	}
	else
		line->color2 = rgb_to_int(255, 255, 255);
	return (1);
}
