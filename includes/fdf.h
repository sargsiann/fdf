/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:12:50 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 18:57:24 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "libft.h"
# include "gnl.h"
# include <stdio.h>
# include <fcntl.h>

# define DEF_DIM 100
# define DEF_ANGLE 120

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
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef	struct	s_line
{
	t_point point1;
	t_point	point2;
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



# endif