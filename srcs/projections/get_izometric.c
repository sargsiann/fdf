/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_izometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:01:03 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/04 18:27:30 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	get_izometric(t_line *line)
{
	int	prev_x1;
	int	prev_x2;
	int	prev_y1;
	int	prev_y2;

	prev_x1 = line->x1;
	prev_x2 = line->x2;
	prev_y1 = line->y1;
	prev_y2 = line->y2;
	line->x1 = (prev_x1 - prev_y1) * cos(0.523599);
	line->x2 = (prev_x2 - prev_y2) * cos(0.523599);
	line->y1 = (prev_x1 + prev_y1) * sin(0.523599) - line->z1;
	line->y2 = (prev_x2 + prev_y2) * sin(0.523599) - line->z2;
}