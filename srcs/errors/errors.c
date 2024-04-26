/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:33:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/04/26 20:31:39 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int check_format(char *file_name)
{
	int i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] != 'f' || file_name[i - 2] != 'd' ||
		 file_name[i - 3] != 'f' || file_name[i - 4] != '.')
		return (0);
	return (1);
}

int	check_line_len(char *data)
{
	int i;
	int line_len;

	i = 0;
	line_len = 0;
	if (!data)
		return (0);
	while (data[i])
	{
		if (data[i] == '\n' || data[i + 1] == '\0')
		{
			line_len = i - 1;
			i++;
			break ;
		}
		i++;
	}
	data += i;
	i = 0;
	printf("data: %s\n", data);
	printf("line_len: %d\n", line_len);
	while (data[i] && data[i] != '\n')
		i++;
	printf("i: %d\n", i);
	if (line_len != i)
		return (0);
	return (1);
}

int	check_parsed_map(char *data)
{
	int	i;
    int line_len;

	i = 0;
    line_len = 0;
    if (!data || !check_line_len(data))
        return (0);
	while (data[i])
	{
		if (!ft_isalnum(data[i]) && data[i] != 32 && data[i] != '\n')
			return (0);
        i++;
	}
	return (1);
}

int handle_errors(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Argument size are not correct", 30);
		return (0);
	}
	if (!check_format(argv[1]))
	{
		write(1, "File format is not correct", 27);
		return (0);
	}
	return (1);
}
