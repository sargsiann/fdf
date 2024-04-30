/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:27:42 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 19:49:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"

void    init(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
    data->image = malloc(sizeof(t_img));
    data->image->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
    data->image->addr = mlx_get_data_addr(data->image->img,
    &(data->image->bpp), &(data->image->line_size), &(data->image->endian));
	mlx_key_hook(data->win, &key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_loop(data->mlx);
}