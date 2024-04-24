#include "fdf.h"

void my_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	if (data->endian == 0)
	{
		dst[0] = color;
		dst[1] = color >> 8;
		dst[2] = color >> 16;
		dst[3] = color >> 24;
	}
	else
	{
		dst[0] = color >> 24;
		dst[1] = color >> 16;
		dst[2] = color >> 8;
		dst[3] = color;
	}
}