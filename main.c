#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
}				t_data;

int	loop_hook(void *param)
{
	t_data *data = (t_data *)param;
	static int x = 0;
	static int y = 0;
	static int color = 0x00000000;
	mlx_pixel_put(data->mlx, data->win, y, x, color);
	if (x == 500)
	{
		x = 0;
		y++;
	}
	if (y == 500)
	{
		y = 0;
	}
	x++;
	color+=0x00000256;
	return (0);
}

int	mouse_handler(int mouse, void *param)
{
	if (mouse == 1)
		printf("Left click\n");
	else if (mouse == 2)
		printf("Right click\n");
	else if (mouse == 3)
		printf("Middle click\n");
	return (0);
}


int key_handler(int keycode, void *param)
{
	t_data *data = (t_data *)param;

	if (keycode == 53)
	{
		system("leaks a.out");
		exit(0);
	}
	printf("keycode: %d\n", keycode);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	struct s_data data;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	win = mlx_new_window(mlx, 500, 500, "Hello World!");
	if (win == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	data.mlx = mlx;
	data.win = win;
	mlx_key_hook(win, key_handler, &data);
	mlx_mouse_hook(win, mouse_handler, &data);
	mlx_loop_hook(mlx, loop_hook, &data);
	mlx_loop(mlx);
	system("leaks a.out");
	return (0);
}