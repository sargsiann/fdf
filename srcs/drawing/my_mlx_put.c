/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:50:31 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 21:16:36 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	my_mlx_put(t_img *image, int x, int y, int color)
{
	char	*address;

	address = image->address + (image->bpp * x) / 8 + y *
	image->line_len;
	if (image->endian == 0)
	{
		address[0] = color;
		address[1] = color >> 8;
		address[2] = color >> 16;
		address[3] = color >> 24;
	}
	else
	{
		address[0] = color >> 24;
		address[1] = color >> 16;
		address[2] = color >> 8;
		address[3] = color;
	}
}