/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:52:50 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 01:33:52 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c && str[i] != c + 32)
		i++;
	return (i);
}

int	hex_to_int(char *hex)
{
	int	i;
	int	res;
	char *symbols = "0123456789ABCDEF";

	i = 0;
	res = 0;
	while (hex[i] && hex[i] != ' ')
	{
		res = res * 16 + index_of(symbols, hex[i]);
		i++;
	}
	return (res);
}