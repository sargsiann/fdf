/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:20:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 23:16:29 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int move(char *a)
{
	int	i;

	i = 0;
	while (ft_isalnum(a[i]) || a[i] == 32)
		i++;
	return (i);
}

static int get_vertical(t_line *line, char **map, int *x, int *y)
{
		
}

int	get_horizontal(t_line *line, char **map, int x, int y)
{
	line->x1 = x;
	line->x2 = y;
	line->height1 = ft_atoi(map[y] + x);
	x += move(map[y] + x);
	if (map[y][x] == ',' && map[y][x + 1] ==  '0' && map[y][x + 2] == 'x')
	{
		x += 3;
		line->color1 = ft_hex_to_dec(map[y][x + 1]);
	}
	else
		line->color1 = rgb_to_int(255, 255, 255);
	x += move(map[y] + x);
	if (map[y] == 0)
		return (-1);
	line->x2 = x + 100;
	line->y2 = y + 100;
	line->height2 = ft_atoi(map[y] + x);
	x += move(map[y] + x);
	if (map[y][x] == ',' && map[y][x + 1] ==  '0' && map[y][x + 2] == 'x')
	{
		x += 3;
		line->color2 = ft_hex_to_dec(map[y][x + 1]);
	}
	else
		line->color2 = rgb_to_int(255, 255, 255);
	return (1);
}

static int get_points_and_draw(t_line *line, int x, int y, char **map, t_data *data)
{
	if (get_horizontal(line, map, x, y) != -1)
	{
		if (line->x2 < line->x1)
			line->sx = -1;
		else
			line->sx = 1;
		line->dx = abs(line->x1 - line->x2);
		line->dy = abs(line->y1 - line->y2);
		if (line->y2 < line->y1)
			line->sy = -1;
		else
			line->sy = 1;
	}
	if (get_vertical(line, map, x, y) != -1)
	{
		if (line->x2 < line->x1)
			line->sx = -1;
		else
			line->sx = 1;
		line->dx = abs(line->x1 - line->x2);
		line->dy = abs(line->y1 - line->y2);
		if (line->y2 < line->y1)
			line->sy = -1;
		else
			line->sy = 1;
	}
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
				get_points_and_draw(&line, i, j, map, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img,
		WIN_WIDTH, WIN_HEIGHT);
}