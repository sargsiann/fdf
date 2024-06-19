/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:49:05 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 00:12:27 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	rgb_to_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	red(int color, int endian)
{
	if (endian == 0)
		return (color >> 24);
	return (color);
}

int	green(int color, int endian)
{
	if (endian == 0)
		return (color >> 16);
	return (color >> 8);
}

int	blue(int color, int endian)
{
	if (endian == 0)
		return (color >> 8);
	return (color >> 16);
}

