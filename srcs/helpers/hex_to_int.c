/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:52:50 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/15 18:48:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c && str[i] != c - 32)
		i++;
	return (i);
}

int	hex_to_int(char *hex)
{
	int		i;
	int		res;
	char	*symbols;
	int		k;

	i = 0;
	res = 0;
	k = 1;
	symbols = "0123456789ABCDEF";
	while (hex[i] && hex[i] != ' ')
		i++;
	i--;
	while (hex[i] && hex[i] != 'x')
	{
		res = res + k * index_of(symbols, hex[i]);
		k = k * 16;
		i--;
	}
	return (res);
}
