/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:23:50 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 20:29:23 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_mlx(t_mlx *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_window = mlx_new_window(fdf->mlx, 1920, 1080, "fdf");
	fdf->image = malloc(sizeof(t_img));
	fdf->image->img = mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->image->address = mlx_get_data_addr(fdf->image->img,
			&fdf->image->bpp, &fdf->image->line_len,
			&fdf->image->endian);
	mlx_key_hook(fdf->mlx_window, key_hook, fdf);
	mlx_hook(fdf->mlx_window, 17, 0, close_win, fdf);
	mlx_loop(fdf->mlx);
}