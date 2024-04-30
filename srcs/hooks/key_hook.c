/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:33:55 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/30 19:39:21 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int key_hook(int key, void *param)
{
	t_data *data = (t_data *)param;
	if (key == 53)
	{
		free(data->map);
		free(data->image);
		exit(0);
	}
	return (0);
}
