/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_neighbours.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:07:04 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 02:04:55 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	get_horizontal_n(t_line *line, int x, int y, char *line_str)
{
	int	move_index;

	move_index = move(line_str, "0123456789,x ");
	printf("move_index: %d\n", move_index);
	// init_point(line->point1, line_str, x, y);
	// if (line_str[move_index] == 0)
		// return ;
	// init_point(line->point2, line_str + move(line_str, "0123456789,x ")
	// ,x + 100, y + 100);
}

static char	*find_point_address(int x, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (x == 0)
				return (line + i);
			x--;
		}
		i++;
	}
	return (NULL);
}

void	get_vertical_n(t_line *line, int x, int y, char *line_str)
{
	int	move_index;

	move_index = move(line_str, "0123456789,x ");
	if (!line->point1)
		init_point(line->point1, line_str, x, y);
	if (line_str[move_index] == 0)
		return ;
	init_point(line->point2, find_point_address(x, line_str), x, y + 100);
}
