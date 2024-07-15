/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:02:31 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/15 18:48:05 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_win(t_mlx *fdf)
{
	free_map(fdf->map);
	mlx_clear_window(fdf->mlx, fdf->mlx_window);
	mlx_destroy_window(fdf->mlx, fdf->mlx_window);
	free(fdf);
	exit(0);
	return (0);
}
