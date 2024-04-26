/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:12:15 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 16:12:21 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void draw_line_xiaolin(int x1, int y1, int x2, int y2, t_img *data)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int x = x1;
	int y = y1;
	int x_inc = x1 < x2 ? 1 : -1;
	int y_inc = y1 < y2 ? 1 : -1;
	int error = dx - dy;
	int error2;

	while (x != x2 || y != y2)
	{
		my_pixel_put(data, x, y, rgb_to_int(255, 255, 255));
		error2 = error * 2;
		if (error2 > -dy)
		{
			error -= dy;
			x += x_inc;
		}
		if (error2 < dx)
		{
			my_pixel_put(data, x + floor(x_inc), y, rgb_to_int(200, 200, 200));
			my_pixel_put(data, x + 2 * floor(x_inc), y, rgb_to_int(150, 150, 150));
			my_pixel_put(data, x + 3 * floor(x_inc), y, rgb_to_int(100, 100, 100));
			my_pixel_put(data, x - 1, y + y_inc, rgb_to_int(200, 200, 200));
			my_pixel_put(data, x - 2, y + y_inc, rgb_to_int(150, 150, 150));
			my_pixel_put(data, x - 3, y + y_inc, rgb_to_int(100, 100, 100));
			error += dx;
			y += y_inc;
		}
	}
}
