/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:20:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 21:59:35 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int get_vertical(t_line *line, char **map, int *x, int *y)
{
	
}

static int get_horizontal(t_line *line, char **map, int *x, int *y)
{
	line->x1 = *x;
	line->y1 = *y;
	line->height1 = ft_atoi(map[*y] + *x);
	
}

static int get_points_and_draw(t_line *line, int *x, int *y, char **map, t_data *data)
{
	if (get_horizontal(line, map, x, y) != -1)
		draw_line(data, line);
	if (get_vertical(line, map, x, y) != -1)
		draw_line(data, line);
}

void	draw_map(char **map, t_data *data)
{
	int	i;
	int	j;
	t_line line;
	
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isdigit(map[i][j]) && (j - 1 < 0 || map[i][j - 1] == 32))
				get_points_and_draw(&line, &i, &j, map, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img,
		WIN_WIDTH, WIN_HEIGHT);
}