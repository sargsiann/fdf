/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:52:42 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 01:54:05 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	loop_hook(t_mlx *fdf, t_line *line)
{
	draw_map(line, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_window, fdf->image->img, 0, 0);
	return (0);
}