#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

# define WIN_HEIGHT 1680
# define WIN_WIDTH  1050
# define DEF_COLOR 0xFFFFFF

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	color1;
	int	color2;
	int	height1;
	int	height2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;

}	t_line;

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_size;
    int     endian;
} t_img;

typedef struct s_data
{
    void    *mlx;
    void    *win;    
    t_img   *image;
    char    **map;
}  t_data;


void    init(t_data *data);
int     validate_format(char *argv[]);
char    **get_map(char *argv[]);
int     validate_map(char **map);
int     check_row_size(char **map);
int     check_valid_symbols(char **map);
int     check_for_dublicate(char **map);
int     check_for_order(char **map);
int		check_for_alpha(char *a, int index);
int		check_for_empty(char **map);
void	free_map(char **map);
int		key_hook(int key, void *param);
int		loop_hook(void *param);
int		mouse_hook(int key, int x, int y, void *param);
int		rgb_to_int(int r, int g, int b);
void	draw_map(char **map, t_data *data);
void	draw_line(t_data *data, t_line *line);


#endif