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


#endif