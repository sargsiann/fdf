#include "FdF.h"
#include "mlx.h"


void draw_line_dda(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xinc = dx / (float)steps;
	float yinc = dy / (float)steps;
	float x = x1;
	float y = y1;
	int i = 0;

	while (i <= steps)
	{
		my_put_pixel(data->img, round(x), round(y), rgb_to_int(255, 255, 255));
		x += xinc;
		y += yinc;
		i++;
	}
}

void draw_line_bras(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (1)
	{
		my_put_pixel(data->img, x1, y1, rgb_to_int(255, 255, 255));
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}