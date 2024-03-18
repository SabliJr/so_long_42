/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:40:39 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 10:24:59 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_images(t_data *data);
int		init_window(t_data *data);
void	loop_images(t_data data);
void	destroy_images(t_data data);

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ERR);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			TITTLE);
	if (data->win == NULL)
	{
		free(data->win);
		return (ERR);
	}
	ft_printf("We are inside inti window!\n");
	return (SUCCESS);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, LOCKED,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, W_RAND, &data->img.width,
			&data->img.height);
	data->img.coin1 = mlx_xpm_file_to_image(data->mlx, COIN1, &data->img.width,
			&data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btn_realease,
		&data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit_l);
	mlx_destroy_image(data.mlx, data.img.coin1);
	mlx_destroy_display(data.mlx);
}
