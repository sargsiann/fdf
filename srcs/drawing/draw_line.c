/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 04:31:22 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/16 11:06:13 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	get_gradient(t_line *line, float t)
{
	int	red;
	int	green;
	int	blue;

	red = (line->color1 >> 16) + ((line->color2 >> 16) - (line->color1 >> 16))
		* t;
	green = (line->color1 >> 8 & 0xFF) + ((line->color2 >> 8 & 0xFF)
			- (line->color1 >> 8 & 0xFF)) * t;
	blue = (line->color1 & 0xFF) + ((line->color2 & 0xFF)
			- (line->color1 & 0xFF)) * t;
	return ((red << 16) + (green << 8) + blue);
}

void	init_line(t_line *line)
{
	if (line->x1 > line->x2)
		line->sx = -1;
	else
		line->sx = 1;
	if (line->y1 > line->y2)
		line->sy = -1;
	else
		line->sy = 1;
	if (line->color1 == 0)
		line->color1 = DEF_COLOR;
	if (line->color2 == 0)
		line->color2 = DEF_COLOR;
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->dx > line->dy)
		line->err = line->dx / 2;
	else
		line->err = -line->dy / 2;
}

static void	logic(t_line *line, t_mlx *mlx, int i, float dim)
{
	if (line->err * 2 > -line->dy)
	{
		line->err -= line->dy;
		line->x1 += line->sx;
	}
	else if (line->err * 2 < line->dx)
	{
		line->err += line->dx;
		line->y1 += line->sy;
	}
	my_mlx_put(mlx, line->x1, line->y1, get_gradient(line, (float)i / dim));
}

void	draw_line(t_line *line, t_mlx *mlx)
{
	float	dim;
	int		i;

	if (line->x1 > DEF_WIN_X || line->x1 < 0 || line->y1 > DEF_WIN_Y
		|| line->y1 < 0)
		return ;
	if (line->x2 > DEF_WIN_X || line->x2 < 0 || line->y2 > DEF_WIN_Y
		|| line->y2 < 0)
		return ;
	dim = (float)sqrt(pow(line->x2 - line->x1, 2) + pow(line->y2 - line->y1,
				2));
	i = 0;
	init_line(line);
	while (1)
	{
		logic(line, mlx, i, dim);
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break ;
		i++;
	}
}
