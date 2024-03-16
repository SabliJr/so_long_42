/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:14:36 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/15 23:44:01 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	handle_btn_realease(t_data *data);
int	handle_keypress(int keysystem, t_data *data);
int	handle_resize(t_data *data);
void	move_msg(t_data *data);

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}

int	handle_keypress(int keysystem, t_data *data)
{
	if (keysystem == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	else if (ft_strchr("wasd", keysystem))
		move_player(data, keysystem);
	return (0);
}

int	handle_btn_realease(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}

void	move_msg(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(PEACH, 1);
	printf("Moves counter : %d\n", data->steps_count);
	ft_putstr_fd(RESET, 1);
}