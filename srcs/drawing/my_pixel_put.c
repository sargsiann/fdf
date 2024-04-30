/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:13:59 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 22:20:59 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	char	*p_address;

	p_address = img->addr + (img->bpp/8) * x + y * (img->line_size);
	if (img->endian == 0)
	{
		p_address = color >> 24;
		p_address[1] = color >> 16;
		p_address[2] = color >> 8;
		p_address[3] = color; 
	}
	else
	{
		p_address = color;
		p_address[1] = color >> 8;
		p_address[2] = color >> 16;
		p_address[3] = color >> 24;
	}
}