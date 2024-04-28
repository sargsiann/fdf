/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_symbols.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:45:52 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/29 00:11:40 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int check_for_alpha(char *a, int index)
{
    char c = 'g';
    while (c < 'z')
    {
        if (*a == c || *a == c - 32)
        {
            if (*a == 'x' || *a == 'X')
            {
                if (index - 1 >= 0 && *(a - 1) == '0')
                    return (1);
                return (0);
            }
            return (0);
        }
        c++;
    }
    return (1);
}

static int check_symbol_validance(char *c, int index)
{
    return (*c != ' ' && !ft_isdigit(*c) 
            && *c != ',' && !check_for_alpha(c, index));
}

int check_valid_symbols(char **map)
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
            if (check_symbol_validance(&map[i][j],j))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}