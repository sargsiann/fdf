/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:29:47 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 17:03:31 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	check_by_name(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	return (file[len] == 'f'
		&& file[len - 1] == 'd'
		&& file[len - 2] == 'f'
		&& file[len - 3] == '.');
}

static int	check_by_access(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

int	check_file_name(char *file)
{
	return (check_by_name(file) && check_by_access(file));
}