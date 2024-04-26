#include "../../fdf.h"

static void   parse_point(char *point)
{
    
}

void    draw_map(char **map_matrix)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map_matrix[i])
    {
        j = 0;
        while (map_matrix[i][j])
        {
            
            j++;
        }
        i++;
    }
}