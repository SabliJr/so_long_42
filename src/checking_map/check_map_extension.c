/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:14 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/14 22:40:46 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_extention(char *path)
{
	int fd;
	size_t path_len;

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