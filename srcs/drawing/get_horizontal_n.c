/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_horizontal_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 04:25:07 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/04 18:25:51 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	get_point1(t_line *line, t_point *point, char *line_str, int j_tmp)
{
	line->x1 = point->x;
	line->y1 = point->i;
	line->z1 = ft_atoi(&line_str[j_tmp]);
	j_tmp += move(&line_str[j_tmp],"0123456789,");
	if (line_str[j_tmp] == 'x')
	{
		j_tmp+=1;
		line->color1 = hex_to_int(&line_str[j_tmp]);
	}
	else
	{
		line->color1 = hex_to_int("0xff0000");
	}
}

static void	get_point2(t_line *line, t_point *point, char *line_str, int j_tmp)
{
	line->x2 = point->x + 50;
	line->y2 = point->i;
	line->z2 = ft_atoi(&line_str[j_tmp]);
	j_tmp += move(&line_str[j_tmp],"0123456789,");
	if (line_str[j_tmp] == 'x')
	{
		j_tmp+=1;
		line->color2 = hex_to_int(&line_str[j_tmp]);
	}
	else
	{
		line->color2 = hex_to_int("0xff0000");
	}
}

void	get_horizontal_n(t_point *point, char *line_str, t_mlx *mlx)
{
	t_line	line;
	int		j_tmp;
	
	j_tmp = point->j;
	get_point1(&line, point, line_str, j_tmp);
	j_tmp += move(&line_str[j_tmp],"0123456789,xabcdefABCDEF") + 1;
	if (!line_str[j_tmp])
		return ;
	get_point2(&line, point, line_str, j_tmp);
	point->j += move(&line_str[j_tmp],"0123456789,xabcdefABCDEF");
	get_izometric(&line);
	draw_line(&line, mlx);
}