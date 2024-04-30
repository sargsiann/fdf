/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:32:26 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/29 18:37:26 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int validate_map(char **map)
{
    if (!map)
    {
        perror("Invalid Map");
        return (0);
    }
    if (!check_row_size(map))
    {
        perror("Invalid line size");
        return 0;
    }
    if (!check_valid_symbols(map))
    {
        perror("Invalid symbols in file");
        return (0);
    }
    if (!check_for_dublicate(map))
    {
        perror("Duplicates in file");
        return (0);
    }
    if (!check_for_order(map))
	{
		perror("Invalid point order");
		return (0);
	}
	if (!check_for_empty(map))
	{
		perror("Empty values in Map");
		return (0);
	}
    return (1);
}