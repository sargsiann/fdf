#ifndef FDF_H
# define FDF_H
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;


typedef struct s_data
{
	void *mlx;
	void *win;
	t_img *img;
} t_data;

int rgb_to_int(int r, int g, int b);
int key_handler(int keycode, t_data *data);
int mouse_handler(int button, int x, int y, t_data *data);
int expose_handler(t_data *data);
int loop_handler(t_data *data);
int my_put_pixel(t_img *img, int x, int y, int color);
int draw_square(t_img *img, int x, int y, int size, int color);
void draw_line_dda(t_data *, int x1, int y1, int x2, int y2);


#endif