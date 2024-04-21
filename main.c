#include <stdio.h>
#include "FdF.h"
#include <stdlib.h>
#include "mlx.h"


int rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int my_put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	if (img->endian == 0)
		*(unsigned int *)dst = color;
	else
	{
		*(unsigned int *)(dst) = color >> 24;
		*(unsigned int *)(dst + 1) = color >> 16;
		*(unsigned int *)(dst + 2) = color >> 8;
		*(unsigned int *)(dst + 3) = color;
	}
	return (0);
}

int expose_handler(t_data *data)
{
	printf("Hello world!\n");
	return (0);
}

int loop_handler(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int draw_square(t_img *img, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}



int mouse_handler(int button, int x, int y, t_data *data)
{
	printf("Button: %d, x: %d, y: %d\n", button, x, y);
	if (button == 1)
	{
		printf("dda\n");
		draw_line_dda(data, 0, 0, x, y);
	}
	if (button == 2)
	{
		printf("bras\n");
		draw_line_bras(data, 0, 0, x, y);
	}

	return (0);
}

int key_handler(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		system("leaks a.out");
		exit(0);
	}
	return (0);
}

int main()
{
	t_data data;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	data.img = (t_img *)malloc(sizeof(t_img));
	data.img->img = mlx_new_image(data.mlx, 1920, 1080);
	data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bits_per_pixel, &data.img->line_length, &data.img->endian);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_loop_hook(data.mlx, loop_handler, &data);
	mlx_expose_hook(data.win, expose_handler, &data);
	mlx_loop(data.mlx);
}

