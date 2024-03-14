/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:21:38 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/14 18:50:42 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_player(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->map.map[x])
	{
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == 'P')
			{
				data->p_i = x;
				data->p_j = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
}