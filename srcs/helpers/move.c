/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:30:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/15 18:49:08 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	int	includes(char c, char *pattern)
{
	int	i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	move(char *str, char *by_pattern)
{
	int	i;

	i = 0;
	while (str[i] && includes(str[i], by_pattern))
		i++;
	return (i);
}
