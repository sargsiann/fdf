/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:25:00 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/09 11:41:32 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	key_hook(int keycode, t_mlx *fdf)
{
	if (keycode == 53)
	{
		free_map(fdf->map);
		mlx_clear_window(fdf->mlx, fdf->mlx_window);
		mlx_destroy_window(fdf->mlx, fdf->mlx_window);
		free(fdf);
		exit(0);
	}
	return (0);
}