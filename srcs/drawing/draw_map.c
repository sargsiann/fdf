/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:02:01 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 02:04:36 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw_map(t_line *line, t_mlx *mlx)
{
	int	i;
	int	j;
	int	x;

	line = malloc(sizeof(line));
	i = 0;
	j = 0;
	x = 0;
	while (mlx->map[i])
	{
		j = 0;
		x = 0;
		while (mlx->map[i][j])
		{
			if (ft_isdigit(mlx->map[i][j]))
			{
				// if (mlx->map[i] + 1 != NULL)
					// get_vertical_n(line, x, i, mlx->map[i] + j);
				if (mlx->map[i][j + 1] != 0)
				{
					get_horizontal_n(line, x, i, mlx->map[i] + j);
				}
				draw_line(line, mlx);
				j += move(mlx->map[i] + j, "0123456789x,");
				if (mlx->map[i][j] == 0)
					break ;
				x++;
			}
			j++;
		}
		i++;
	}
}