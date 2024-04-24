/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:13:05 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/24 19:03:35 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int expose_hook(t_data *data)
{
	printf("hello");
	return (0);
}

int mouse_hook(int button, int x, int y, t_data *data)
{
	static int x1 = 0;
	static int y1 = 0;
	static int x2 = 0;
	static int y2 = 0;
	
	printf("Button: %d, x: %d, y: %d\n", button, x, y);
	
	if (button == 1)
	{
		x1 = x;
		y1 = y;
	}
	else if (button == 2)
	{
		x2 = x;
		y2 = y;
		draw_line_xiaolin(x1, y1, x2, y2, data->img);
	}
	return (0);
}

int loop_hook(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int main()
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "FdF");
	data.img = (t_img *)malloc(sizeof(t_img));
	data.img->img = mlx_new_image(data.mlx, 1920, 1080);
	data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bpp, &data.img->line_len, &data.img->endian);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}