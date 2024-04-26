/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:55:45 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 19:55:26 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	*map = NULL;

	if (handle_errors(argc) == 0)
	{
		return (1);
	}
	map = create_map_char(argv[1]);
	if (check_parsed_map(map) == 0)
	{
		return (1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "FdF");
	data.img = (t_img *)malloc(sizeof(t_img));
	data.img->img = mlx_new_image(data.mlx, 1920, 1080);
	data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bits_per_pixel,
			&data.img->line_length, &data.img->endian);
	mlx_key_hook(data.win, key_hooks, &data);
	mlx_mouse_hook(data.win, mouse_hooks, &data);
	mlx_loop_hook(data.mlx, loop_hooks, &data);
	mlx_loop(data.mlx);
}
