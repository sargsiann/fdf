/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:33:06 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/28 21:45:48 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../fdf.h"

static int check_for_point(char *a, int index)
{
    if (index - 1 < 0)
    {
        if (*a == '-' && *(a + 1) && ft_isdigit(*(a + 1)))
            return (1);
        else if (ft_isdigit(*a))
            return (1);
        return (0);
    }
    if (*a == '-' && *(a + 1) && ft_isdigit(*(a + 1)) && *(a - 1) == ' ')
            return (1);
    else if (ft_isdigit(*a) && *(a - 1) == ' ')
        return (1);
    return (0);
}

static int define_row_len(char **map)
{
    int i;
    int j;
    int row_len;

    i = 0;
    j = 0;
    row_len = 0;
    while (map[i][j])
    {
        if (check_for_point(&map[i][j],j))
            row_len++;
        j++;
    }
    return (row_len);
}

int check_row_size(char **map)
{
    int i;
    int j;
    int row_len;
    int count;

    i = 0;
    j = 0;
    row_len = define_row_len(map);
    count = 0;
    while (map[i])
    {
        j = 0;
        count = 0;
        while (map[i][j])
        {
            if (check_for_point(&map[i][j],j))
                count++;
            j++;
        }
        if (count != row_len)
            return (0);
        i++;
    }
    return (1);
}