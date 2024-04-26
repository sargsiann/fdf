/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:11:43 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 16:24:58 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	mouse_hooks(int button, int x, int y, t_data *data)
{
	static int	x1 = -1;
	static int	y1 = -1;
	static int	x2 = -1;
	static int	y2 = -1;

	printf("Button: %d, x: %d, y: %d\n", button, x, y);
	if (button == 1)
	{
		x1 = x;
		y1 = y;
	}
	else if (button == 2)
	{
		x2 = x;
		y2 = y;
		draw_line_xiaolin(x1, y1, x2, y2, data->img);
	}
	return (0);
}
