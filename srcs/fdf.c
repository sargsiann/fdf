/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:51:40 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/15 18:42:45 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (argc != 2 || !check_file_name(argv[1]))
		return (1);
	mlx = malloc(sizeof(mlx));
	mlx->map = get_map(argv[1]);
	if (!mlx->map || !symbol_check(mlx->map))
	{
		free_map(mlx->map);
		free(mlx);
		return (1);
	}
	init_mlx(mlx);
}
