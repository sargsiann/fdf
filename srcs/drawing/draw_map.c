/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 04:22:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/13 20:04:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"


void	draw_map(t_mlx *mlx)
{
	t_point	point;
	int		k;

	point.x = 0;
	point.i = DEF_WIN_Y / 2 - 200;
	point.j = 0;
	k = 0;
	while (mlx->map[k])
	{
		point.j = 0;
		point.x = 800;
		while (mlx->map[k][point.j])
		{
			if (ft_isdigit(mlx->map[k][point.j]) || mlx->map[k][point.j] == '-')
			{
				if (mlx->map[k + 1] != NULL)
					get_vertical_n(&point, mlx->map[k], mlx);
				get_horizontal_n(&point, mlx->map[k], mlx);
				point.j += move(&mlx->map[k][point.j], "-0123456789,xabcdefABCDEF");
				point.x += 15;
			}
			if (mlx->map[k][point.j] == '\0')
				break ;
			point.j++;
		}
		point.i += 15;
		k++;
	}
}
