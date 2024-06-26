/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:59:04 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/19 16:51:28 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*ft_strdup(char const *str)
{
	int		size;
	int		i;
	char	*a;

	size = ft_strlen(str);
	i = 0;
	a = (char *)malloc(size + 1);
	if (str == NULL || !a)
		return (NULL);
	while (str[i] != '\0')
	{
		a[i] = str[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
