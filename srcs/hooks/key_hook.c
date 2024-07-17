/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:25:00 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/16 17:52:36 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	key_hook(int keycode, t_mlx *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->mlx_window);
		mlx_destroy_image(fdf->mlx, fdf->image->img);
		free(fdf->image);
		free_map(fdf->map);
		free(fdf);
		system("leaks fdf");
		exit(0);
	}
	return (0);
}
