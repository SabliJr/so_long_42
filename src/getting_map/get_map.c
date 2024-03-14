/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:45:53 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/14 18:50:35 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// void	ft_free(char **arr)
// {
// 	size_t	k;

// 	k = 0;
// 	while (arr[k] != NULL)
// 	{
// 		free(arr);
// 		k++;
// 	}
// 	free(arr);
// 	arr = NULL;
// 	return ;
// }

int	get_map_lines_num(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error: Failed to open the file");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			// free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	get_input_in_map(int row, size_t cloumn, int x, t_data *data)
{
	char	*lines;

	lines = get_next_line(data->map.fd);
	while (lines != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(lines) + 1, sizeof(char));
		if (!data->map.map[row])
			return (free(data->map.map));
		while (lines[x] != '\0')
			data->map.map[row][cloumn++] = lines[x++];
		data->map.map[row++][cloumn] = '\0';
		x = 0;
		cloumn = 0;
		// free(lines);
		lines = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}

void	create_map(t_data *data, char *path)
{
	int row;
	size_t cloumn;
	int x;

	x = 0;
	row = 0;
	cloumn = 0;
	data->map.line_count = get_map_lines_num(path);
	if (!data->map.line_count)
		error_msg("The map file is empty!\n");
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!data->map.map)
		return ;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		ft_printf("Error: Failed to open the file\n");
	else
	{
		get_input_in_map(row, cloumn, x, data);
		close(data->map.fd);
	}
}