// DDA LINE DRAW ALGORITHM
#include "FdF.h"

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

// BRASENHAM LINE DRAW ALGORITHM

void draw_line_bras(t_data *data, int x1, int y1, int x2, int y2)
{
	
}