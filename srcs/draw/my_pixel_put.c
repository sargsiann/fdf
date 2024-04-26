/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:47:02 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 19:47:04 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (img->endian == 0)
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
