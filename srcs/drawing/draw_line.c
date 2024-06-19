/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:20:04 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 01:57:03 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	void	init_line(t_line *line)
{
	line->dx = abs(line->point2->x - line->point1->x);
	line->dy = abs(line->point2->y - line->point1->y);
	if (line->point1->x < line->point2->x)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->point1->y < line->point2->y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

static	int get_color(t_line *line, int t)
{
	int	color;

	line->point1->color->red = line->point1->color->red + 
	t * (line->point2->color->red - line->point1->color->red);
	line->point1->color->green = line->point1->color->green +
	t * (line->point2->color->green - line->point1->color->green);
	line->point1->color->blue = line->point1->color->blue +
	t * (line->point2->color->blue - line->point1->color->blue);
	color = rgb_to_int(line->point1->color->red, line->point1->color->green,
	line->point1->color->blue, line->point1->color->a);
	return (color);
}

void	draw_line(t_line *line, t_mlx *mlx)
{
	int	grad_var;
	int	d;

	d = (int )sqrt(pow(line->dx, 2) + pow(line->dy, 2));
	grad_var = 0;
	init_line(line);
	while (line->point1->x != line->point2->x
		|| line->point1->y != line->point2->y)
	{
		line->color = get_color(line, grad_var / d);
		my_mlx_put(mlx->image, line->point1->x, line->point1->y, line->color);
		if (2 * line->err > -line->dy)
		{
			line->err -= line->dy;
			line->point1->x += line->sx;
		}
		if (2 * line->err < line->dx)
		{
			line->err += line->dx;
			line->point1->y += line->sy;
		}
		grad_var++;
	}
}