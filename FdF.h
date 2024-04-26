#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_data;

int		key_hooks(int key, void *data);
int		mouse_hooks(int button, int x, int y, t_data *data);
int		rgb_to_int(int r, int g, int b);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw_line_xiaolin(int x1, int y1, int x2, int y2, t_img *data);
int		loop_hooks(t_data *data);

# endif