/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:03:21 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/16 14:29:28 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_map(t_data *data)
{
	int len;

	len = ft_strlen(data->map.map[0]) - 1;
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
	data->win_width = (len * IMG_SIZE);
}