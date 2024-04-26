/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:33:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 19:57:55 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// verjum .fdf
// toxeri erk havasar 

static int get_line_len(char *data)
{
	int i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n' || data[i] == 0)
			return i;
		i++;
	}
	return i;
}

int	check_parsed_map(char *data)
{
	int	i;
    int line_len;

	i = 0;
    line_len = 0;
    if (!data)
        return (0);
	while (data[i])
	{
		if (!ft_isalnum(data[i]) && data[i] != 32 && data[i] != '\n')
			return (0);
        i++;
	}
	return (1);
}



int handle_errors(int argc)
{
	if (argc != 2)
		return (0);
    return (1);
}
