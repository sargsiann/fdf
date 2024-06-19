/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:12:50 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 01:54:47 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "libft.h"
# include "gnl.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define DEF_DIM 100
# define DEF_ANGLE 120
# define DEF_COLOR 0xFFFFFF

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	a;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef	struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
	t_img	*image;
	char	**map;
}	t_mlx;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	t_color	*color;
}	t_point;

typedef	struct	s_line
{
	t_point *point1;
	t_point	*point2;
	int		sx;
	int		sy;
	int		dx;
	int		dy;
	int		color;
	int		err;
	int		angle;
}	t_line;

int		validation(int argc, char **argv);
int		check_file_name(char *file);
char	**get_map(char *file);
void	free_map(char **map);
int		symbol_check(char	**map);
int		row_size_check(char **map);
int		move(char *str, char *by_pattern);
int		check_by_order(char	**map);
void	free_map(char **map);
void	init_mlx(t_mlx *fdf);
int		key_hook(int keycode, t_mlx *fdf);
int		close_win(t_mlx *fdf);
void	my_mlx_put(t_img *image, int x, int y, int color);
int		rgb_to_int(int r, int g, int b, int a);
int		red(int color, int endian);
int		green(int color, int endian);
int		blue(int color, int endian);
void	draw_line(t_line *line, t_mlx *mlx);
void	draw_map(t_line *line, t_mlx *mlx);
int		hex_to_int(char *hex);
void	init_point(t_point *point, char *line, int x, int y);
void	get_vertical_n(t_line *line, int x, int y, char *line_str);
void	get_horizontal_n(t_line *line, int x, int y, char *line_str);
int		loop_hook(t_mlx *fdf, t_line *line);


# endif