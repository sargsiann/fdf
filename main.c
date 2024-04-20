#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00

typedef struct s_img{
	void *mlx;
	char *address;
	int	bpp;
	int line_size;
	int endian;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_data;


typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

int	color_encoder(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->address + (y * img->line_size + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void	render_background(t_data *data, int color)
{
    int	i;
    int	j;

    if (data->win == NULL)
        return ;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            my_pixel_put(data->img, j++, i, color);
        ++i;
    }
}


int render_rect(t_data *data, t_rect rect)
{
    int	i;
    int j;

    if (data->win == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            my_pixel_put(data->img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

int render(void *param)
{
	t_data *data = (t_data *)param;
	render_background(data, 0xFFFFFF);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
            100, 100, GREEN_PIXEL});
    render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int expose_handler(void *param)
{
	printf("Hello\n");
	return 0;
}

int	mouse_handler(int mouse, int x, int y, void *param)
{
	t_data *data = (t_data *)param;
	if (mouse == 1)
		mlx_pixel_put(data->mlx, data->win, x, y, 0x0000000FF);
	else if (mouse == 2)
		mlx_pixel_put(data->mlx, data->win, x, y, 0x000000000);
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
	data.img = mlx_new_image(mlx, 500, 500);
	data.img->address = mlx_get_data_addr(data.img,&(data.img->bpp),&(data.img->line_size),&(data.img->endian));
	mlx_key_hook(win, key_handler, &data);
	mlx_mouse_hook(win, mouse_handler, &data);
	mlx_expose_hook(win, expose_handler, &data);
	mlx_loop_hook(mlx, render, &data);
	mlx_loop(mlx);
	system("leaks a.out");
	return (0);
}