/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:57:45 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/29 00:49:25 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int check_point_pattern(char *point)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(point);
	while(point[i] && ft_isdigit(point[i]))
		i++;
	if (point[i] && point[i] == ',')
		i++;
	if (point[i] && (point[i + 1] && point[i + 1] == '0'))
		i++;
	if (point[i] && (point[i] == 'x' || point[i] == 'X'))
		i++;
	if (!point[i])
		return (1);
	while(point[i] && (ft_isalpha(point[i]) || ft_isdigit(point[i])))
		i++;
	if (i != len)
	{
		free(point);
		return (0);
	}
	return (1);
}

static char	*get_point_pattern(char *line, int index)
{
	char	*point;
	char	*end;

	end = ft_strchr(&line[index], 32);
	point = ft_substr(line + index, 0,end - line - index);
	if (!point)
		return (NULL);
	return (point);
}

int	check_for_order(char **map)
{
	int		i;
	int		j;
	char	*point;

	i = 0;
	j = 0;
	point = NULL;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((ft_isdigit(map[i][j]) || map[i][j] == '-') && (j - 1 == -1 
			|| map[i][j - 1] == ' '))
			{
				point = get_point_pattern(map[i], j);
				if (!check_point_pattern(point))
					return (0);
				free(point);
			}
			j++;
		}
		i++;
	}
	return (1);
}