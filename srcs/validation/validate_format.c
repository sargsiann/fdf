/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:50:54 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/28 22:56:54 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int  validate_format(char *argv[])
{
    int i;

    i = ft_strlen(argv[1]);
    if (argv[1][i - 1] != 'f' || argv[1][i - 2] != 'd'
        || argv[1][i - 3] != 'f' || argv[1][i - 4] != '.')
    {
        perror("Wrong file format");
        return (0);
    }
    return (1);
}