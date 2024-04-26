/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:33:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 18:11:15 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	check_parsed_map(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (!ft_isdigit(data[i]) && data[i] != 32 && data[i] != '\n')
			return (0);
	}
	return (1);
}



int handle_errors(int argc, char **argv)
{
	char    *map;

	map = NULL;
	if (argc != 2)
	{
		return (0);
	}
	else
	{
		map = create_parsed_map(argv[1]);
		return (check_parsed_map(map));
	}
}
