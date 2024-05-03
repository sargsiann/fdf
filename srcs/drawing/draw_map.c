/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:20:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/05/03 17:35:00 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int move(char *line)
{
	int	i;

	i = 0;
	while (ft_isalnum(line[i]) || line[i] == 32)
		i++;
	return (i);
}

static void get_points_and_draw_2d(t_data *data, t_point *point, t_line *line)
{
	if (get_horizontal_n(data, point, line) != -1)
	{
		line->dx = DEF_DISTANCE;
		line->dy = 0;
		line->sx = 1;
		line->sy = 0;
	}
	if (get_vertical_n(data, point, line) != -1)
	{
		line->dx = 0;
		line->dy = DEF_DISTANCE;
		line->sx = 0;
		line->sy = 1;
	}
}

void	draw_map(char **map, t_data *data)
{
	int		i;
	int		j;
	t_line	ln;
	t_point point;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '-' || ft_isdigit(map[i][j])) 
				&& (j - 1 < 0 || map[i][j - 1] == 32))
			{
				point.point_num++;
				point.x = j;
				point.y = i;
				point.line = map[i];
				get_points_and_draw_2d(data, &point, &ln);
			}
			j++;
		}
		i++;
	}
}