/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:10:13 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/01 09:02:22 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	my_mlx_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if (x < 0 || x >= DEF_WIN_X || y < 0 || y >= DEF_WIN_Y)
		return ;
	dst = mlx->image->address +
	(y * mlx->image->line_len + x * (mlx->image->bpp / 8));
	if (mlx->image->endian == 0)
	{
		dst[0] = color;
		dst[1] = color >> 8;
		dst[2] = color >> 16;
	}
	else
	{
		dst[0] = color >> 16;
		dst[1] = color >> 8;
		dst[2] = color;
	}
}