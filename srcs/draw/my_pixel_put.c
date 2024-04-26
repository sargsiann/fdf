#include "../../fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (img->endian == 0)
	{
		dst[0] = color;
		dst[1] = color >> 8;
		dst[2] = color >> 16;
	}
	else
	{
		dst[2] = color;
		dst[1] = color >> 8;
		dst[0] = color >> 16;
	}
}