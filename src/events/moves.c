/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:28:09 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/15 23:43:23 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_player(t_data *data, char direction);
void	collect_coins(t_data *data, char direction);
int		win_game(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);

int	win_game(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		return (SUCCESS);
	}
	else
		return (SUCCESS);
}

void	collect_coins(t_data *data, char direction)
{
	if ((direction == 'd' && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == 'a' && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == 's' && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == 'w' && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 'd' && data->map.map[data->p_i][data->p_j + 1] == tile)
		|| (direction == 'a' && data->map.map[data->p_i][data->p_j - 1] == tile)
		|| (direction == 's' && data->map.map[data->p_i + 1][data->p_j] == tile)
		|| (direction == 'w' && data->map.map[data->p_i
			- 1][data->p_j] == tile))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1') == SUCCESS
		|| (data->map.can_exit == 0 && check_next_tile(data, direction,
				'E') == SUCCESS))
		return ;
	data->steps_count++;
	collect_coins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	if (direction == 'd')
		data->p_j++;
	else if (direction == 'a')
		data->p_j--;
	else if (direction == 's')
		data->p_i++;
	else if (direction == 'w')
		data->p_i--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
		win_game(data);
	data->map.map[data->p_i][data->p_j] = 'P';
}