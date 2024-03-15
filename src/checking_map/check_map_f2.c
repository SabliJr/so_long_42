/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:14 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/15 18:59:57 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_extention(char *path);
int	check_rectangle(t_data *data);

int	check_extention(char *path)
{
	int		fd;
	size_t	path_len;

	path_len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = (open(path, O_DIRECTORY));
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		if (path[path_len - 4] != '.')
			return (FAILURE);
		if (path[path_len - 3] != 'b')
			return (FAILURE);
		if (path[path_len - 2] != 'e')
			return (FAILURE);
		if (path[path_len - 1] != 'r')
			return (FAILURE);
		return (SUCCESS);
	}
}

int	check_rectangle(t_data *data)
{
    int i;
    size_t j;

    i = 0;
    data->map.line_len = ft_strlen(data->map.map[i]) - 1;
    while (data->map.map[i])
    {
        j = 0;
        while (data->map.map[i][j])
            j++;
        if (j != data->map.line_len)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}