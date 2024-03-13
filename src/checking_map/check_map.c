/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:29:43 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/13 08:18:12 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int check_top_bottom(int row, char **map)
{
    int i;

    i = 0;
    while (map[row][i] && map[row][i] != '\n')
    {
        if (map[row][i] != '1')
            return (FAILURE);
        i++;
    }   
    return (SUCCESS);
}

int check_letters(t_data *data)
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
    if (!data->map.can_exit || !data->map.players_count || !data->map.count_c)
        return (FAILURE);
    else
        return (SUCCESS);
}

int check_edges(int line_count, char **map)
{
    int x;

    x = 0;
    if (check_top_bottom(0, map) == FAILURE
        || (check_top_bottom(line_count, map) == FAILURE))
        return (FAILURE);
    while (x < line_count)
    {
        if (map[x][0] != '1' || map[x][ft_strlen(map[0]) - 2] != '1')
            return (FAILURE);
        x++;
    }
    return (SUCCESS);   
}

int check_recrtangel(t_data *data)
{
    int i;
    size_t  j;

    i = 0;
    j = 0;
    data->map.line_len = ft_strlen(data->map.map[i] - 1);
    while (data->map.map[i])
    {
        while (data->map.map[i][j] && data->map.map[i][j] != '\n')
            j++;
        if (j != data->map.line_len)
            return (FAILURE);
        j = 0;
        i++;
    }
    return (SUCCESS);
}

int check_map(t_data *data)
{
    int x;
    size_t  y;
    
    x = 0;
    y = 0;
    while (data->map.map[x])
    {
        while (y < ft_strlen(data->map.map[x] - 1))
        {
            if (ft_strchr('01CEP', data->map.map[x][y]) == NULL)
                error_msg(OTHER_ERR, data);
            y++;
        }
        y = 0;
        x++;
    }
   if (check_chars(data) == FAILURE)
		error_msg(CHARS_ERR, data);
	if (data->map.players_count > 1)
		error_msg(PLAYER_ERR, data);
	if (check_rectangle(data) == FAILURE)
		error_msg(NOT_REC_ERR, data);
	if (check_edges(data->map.line_count - 1, data->map.map) == FAILURE)
		error_msg(EDGES_ERR, data);
	return (SUCCESS);
}
