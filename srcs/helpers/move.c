/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:30:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 18:52:08 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	move(char *str, char *by_pattern)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(by_pattern, str[i]) != NULL)
		i++;
	return (i);
}