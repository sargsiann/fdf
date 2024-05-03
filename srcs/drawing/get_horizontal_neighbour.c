/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_horizontal_neighbour.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:04:02 by dasargsy          #+#    #+#             */
/*   Updated: 2024/05/03 17:35:15 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int get_horizontal_n(t_data *data, t_point *point, t_line *line)
{
	int	x_tmp;
	
	x_tmp = point->x;
	line->x1 = point->x;
	line->x2 = point->x + DEF_DISTANCE;
	line->y2 = point->y;
	line->height1 = ft_atoi(point->line[point->x]);
	line->y1 = point->y;
	x_tmp += move(point->line + x_tmp);
	if (point->line[point->x] == ',')
	{
		x_tmp += 2;
		line->color1 = ft_hex_to_dec(point->line[x_tmp]);
	}
	else
		line->color1 = rgb_to_int(255, 255, 255);
	if (point->line[x_tmp + 1] == 0)
		return (-1);
	x_tmp += move(point->line + x_tmp);
	line->height2 = ft_atoi(point->line + x_tmp);
	x_tmp += move(point->line + x_tmp);
	if (point->line[x_tmp] == ',')
	{
		x_tmp += 2;
		line->color2 = ft_hex_to_dec(point->line[x_tmp]);
	}
	else
		line->color2 = rgb_to_int(255, 255, 255);
	return (1);
}