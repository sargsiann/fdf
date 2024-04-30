/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:29:31 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 19:40:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	check_for_empty(char **map)
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
			if (ft_isalpha(map[i][j]) && (j - 1 < 0 || map[i][j - 1] == 32))
				return (0);
			if (map[i][j] == ',' && (j == 0 || !ft_isdigit(map[i][j - 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}