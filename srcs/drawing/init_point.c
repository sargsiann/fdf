/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:36:40 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 01:51:52 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	void	init_color(t_color *color, int color_num)
{
	color->red = (color_num >> 16) & 0xFF;
	color->green = (color_num >> 8) & 0xFF;
	color->blue = color_num & 0xFF;
	color->a = 255;
}

void	init_point(t_point *point, char *line, int x, int y)
{
	int	i;
	int	color;
	
	i = 0;
	point = malloc(sizeof(t_point));
	point->color = malloc(sizeof(t_color));
	point->z = ft_atoi(line);
	point->y = y;
	point->x = x;
	i += move(line, "0123456789,");
	if (line[i] && line[i] == '0' && line[i + 1] == 'x')
		i += 2;
	color = hex_to_int(line + i);
	init_color(point->color, color);
}