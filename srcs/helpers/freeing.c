/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:02:31 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/16 17:53:42 by dasargsy         ###   ########.fr       */
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
	mlx_destroy_window(fdf->mlx, fdf->mlx_window);
	mlx_destroy_image(fdf->mlx, fdf->image->img);
	free(fdf->image);
	free_map(fdf->map);
	free(fdf);
	exit(0);
	return (0);
}
