/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:41:51 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 19:22:26 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	int	check_order_pattern(char *point)
{
	int	i;

	i = 0;
	while (ft_isdigit(point[i]))
		i++;	
	if (point[i] == ',' && point[i + 1] == '0')
		i++;
	else if (point[i] == 0 || point[i] == 32)
		return (1);
	else if (point[i] == ',' && point[i + 1] != '0')
		return (0);
	if (point[i] == '0' && point[i + 1] == 'x')
		i++;
	else if (point[i] == '0' && point[i + 1] != 'x')
		return (0);
	if (point[i] == 'x' && ft_isalnum(point[i + 1]))
	{
		while(ft_isalnum(point[i]) )
			i++;
		if (point[i] == 0 || point[i] == 32)
			return (1);
		return (0);
	}
	else
		return (0);
	return (1);
}

int	check_by_order(char	**map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_order_pattern(map[i] + j))
				return (0);
			j += move(map[i] + j, "0123456789abcefx,");
			j++;
		}
		i++;
	}
	return (1);
}