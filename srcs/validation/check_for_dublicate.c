/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_dublicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:34:38 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/28 22:56:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int check_double_symbols(char *sym, int index)
{
    return ((index - 1 >= 0 && *(sym - 1) == *sym)); 
}

int check_for_dublicate(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == ' ' || map[i][j] == ',')
            {
                if (check_double_symbols(&map[i][j],j))
                    return (0);
            }
            j++;
        }
        i++;        
    }
    return (1); 
}