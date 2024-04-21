#include "mlx.h"
#include <stdlib.h>

typedef struct s_img
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_pixel
{
    int x;
    int y;
} t_pixel;

int key_handler(int keycode, void *param)
{
	if (keycode == 53) // 53 is the keycode for ESC key
	{
		exit(0);
	}
	return 0;
}

int rgb_to_int(unsigned char red, unsigned char green, unsigned char blue)
{
    return (red << 16) | (green << 8) | blue;
}

void put_pixel_to_image(t_img *img, t_pixel pixel, int color)
{
    char *dst = img->addr + (pixel.y * img->line_length + pixel.x * (img->bits_per_pixel / 8));
	if (img->endian == 0)
	{
		*(unsigned char *)dst = color;
		*(unsigned char *)(dst + 1) = color >> 8;
		*(unsigned char *)(dst + 2) = color >> 16;
		*(unsigned char *)(dst + 3) = color >> 24;
	}
	else if (img->endian == 1)
	{
		*(unsigned char *)dst = color >> 16;
		*(unsigned char *)(dst + 1) = color >> 8;
		*(unsigned char *)(dst + 2) = color;
		*(unsigned char *)(dst + 3) = color >> 24;
	}
}

void fill_image_with_color(t_img *img, int width, int height, int color)
{
    int x, y;
    t_pixel pixel;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            pixel.x = x;
            pixel.y = y;
            put_pixel_to_image(img, pixel, rgb_to_int(x,y,x + y));
        }
    }
}

int loop_handler(void *param)
{
    t_img *img = (t_img *)param;
    int     win_width = 800;
    int     win_height = 600;
    int     fill_color = 0x00FF0000; // Red color

    fill_image_with_color(img, win_width, win_height, fill_color);
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0); // Display the updated image

    return 0;
}

int main()
{
    t_img   *img;
    int     win_width = 800;
    int     win_height = 600;
    
    img = (t_img *)malloc(sizeof(t_img));
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, win_width, win_height, "Fill Window with Color");
    img->img = mlx_new_image(img->mlx, win_width, win_height);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_key_hook(img->win, key_handler, (void *)0); // Set the exit handler
    mlx_loop_hook(img->mlx, loop_handler, (void *)img); // Set the loop handler
    mlx_loop(img->mlx);

    return 0;
}