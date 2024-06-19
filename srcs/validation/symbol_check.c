/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:44:25 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 17:54:25 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	symbol_check(char	**map)
{
	int		i;
	int		j;
	char	*hex;

	i = 0;
	j = 0;
	hex = "0123456789abcdef ,x";
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(hex, map[i][j]) == NULL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}