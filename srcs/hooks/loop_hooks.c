#include "../../fdf.h"

int loop_hooks(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
    return (0);
}