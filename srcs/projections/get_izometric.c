/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_izometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:01:03 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/15 18:49:37 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	get_izometric(t_line *line, t_mlx *mlx)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;

	x1 = (line->x1 - line->y1) * cos(0.523599);
	y1 = -line->z1 + (line->x1 + line->y1) * sin(0.523599);
	x2 = (line->x2 - line->y2) * cos(0.523599);
	y2 = -line->z2 + (line->x2 + line->y2) * sin(0.523599);
	line->x1 = x1 + 100;
	line->y1 = y1 - 50;
	line->x2 = x2 + 100;
	line->y2 = y2 - 50;
	draw_line(line, mlx);
}
