/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:29:43 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 20:17:56 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	return_res(t_data *data);
int	check_top_bottom(int row, char **map);
int	check_letters(t_data *data);
int	check_edges(int line_count, char **map);
int	check_map(t_data *data);

int	check_top_bottom(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_letters(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'P')
				data->map.players_count++;
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.count_c++;
			else if (data->map.map[data->i][data->j] == 'E')
				data->map.exit_count++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (data->map.players_count > 1)
		return (2);
	if (data->map.exit_count > 1)
		return (3);
	if (!data->map.exit_count || !data->map.players_count || !data->map.count_c)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	check_edges(int line_count, char **map)
{
	int	i;
	int	line_len;

	i = 1;
	if (check_top_bottom(0, map) == FAILURE || check_top_bottom(line_count,
			map) == FAILURE)
		return (FAILURE);
	while (i < line_count)
	{
		line_len = ft_strlen(map[i]) - 2;
		if (map[i][0] != '1' || map[i][line_len] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		len = ft_strlen(data->map.map[x]);
		while (y < len - 1)
		{
			if (ft_strchr("01CEP", data->map.map[x][y]) == NULL)
				error_msg(OTHER_ERR, data);
			y++;
		}
		x++;
	}
	return (return_res(data));
}

int	return_res(t_data *data)
{
	if (check_edges(data->map.line_count - 1, data->map.map) == FAILURE)
		error_msg(EDGES_ERR, data);
	if (check_extention(data->map.path) == FAILURE)
		error_msg(BER_ERR, data);
	if (check_letters(data) == FAILURE)
		error_msg(CHARS_ERR, data);
	if (check_letters(data) == 2)
		error_msg(PLAYER_ERR, data);
	if (check_letters(data) == 3)
		error_msg(MULITPULE_EXITS_ERR, data);
	if (la_algo(data, data->map.count_c) == FAILURE)
		error_msg(MAP_NOT_SOLVABLE, data);
	if (check_rectangle(data) == FAILURE)
		error_msg(NOT_REC_ERR, data);
	return (SUCCESS);
}
