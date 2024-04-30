/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:42:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 19:44:52 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	loop_hook(void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	mlx_put_image_to_window(data->mlx,data->win,data->image->img, WIN_WIDTH, WIN_HEIGHT);
	return (1);
}