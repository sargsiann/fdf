/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:11:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/24 19:02:43 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_data;

int key_hook(int keycode, t_data *data);
int expose_hook(t_data *data);
int mouse_hook(int button, int x, int y, t_data *data);
int loop_hook(t_data *data);
void my_pixel_put(t_img *data, int x, int y, int color);
void draw_line_dda(int x1, int y1, int x2, int y2, t_img *data);
int rgb_to_int(int r, int g, int b);
void draw_line_xiaolin(int x1, int y1, int x2, int y2, t_img *data);


#endif