/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertical_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:17:26 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/09 11:23:55 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	get_point1(t_line *line, t_point *point, char *line_str)
{
	line->x1 = point->x;
	line->y1 = point->i;
	line->z1 = ft_atoi(&line_str[point->j]);
	point->j+=move(&line_str[point->j],"0123456789,");
	if (line_str[point->j] == ',')
	{
		point->j+=1;
		line->color1 = hex_to_int(&line_str[point->j]);
	}
	else
		line->color1 = 0x0000ff;
}

static void	get_point2(t_line *line, t_point *point, char *line_str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = point->x;
	while (line_str[i])
	{
		i++;
		if (ft_isdigit(line_str[i]))
			tmp--;
		if (tmp == 0)
			break ;
	}
	line_str += i;
	line->x2 = point->x;
	line->y2 = point->i + 50;
	line->z2 = ft_atoi(&line_str[point->j]);
	point->j+=move(&line_str[point->j],"0123456789,");
	if (line_str[point->j] == 'x')
	{
		point->j+=1;
		line->color2 = hex_to_int(&line_str[point->j]);
	}
	else
	{
		line->color2 = 0xff0000;
	}
}

void	get_vertical_n(t_point *point, char *line_str, t_mlx *mlx)
{
	t_line	line;

	get_point1(&line, point, line_str);
	get_point2(&line, point, line_str + 1);
	draw_line(&line, mlx);
}