/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:03:21 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/13 14:59:20 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *data)
{
	data->j = 0;
	data->i = 0;
	data->steps_count = 0;
	data->map.can_exit = 0;
	data->map.collected = 0;
	data->map.count_c = 0;
	data->map.exit_count = 0;
	data->map.players_count = 0;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0] - 1) * IMG_SIZE);
}