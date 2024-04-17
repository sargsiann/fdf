#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	void *mlx;
	void *win;
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 1024, "mlx 42");

	x_start = 32;
	y_start = 32;
	x_end = 100;
	y_end = 888;
	color = 0x00FF0000;
	while (y_start < y_end)
	{
		while (x_start < x_end)
		{
			mlx_pixel_put(mlx, win, x_start, y_start, color);
			x_start++;
			y_start++;
		}
		y_start++;
	}
	mlx_loop(mlx);
	return (0);
}