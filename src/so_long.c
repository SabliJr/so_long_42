/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:40:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 18:07:50 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("\e[31mError\nPlease provide a map! \e0\n"));
	create_map(&data, argv[1]);
	init_map(&data);
	check_map(&data);
	init_player(&data);
	init_window(&data);
	init_images(&data);
	render(&data);
	loop_images(data);
	destroy_images(data);
	free(data.mlx);
	if (data.map.map)
		ft_free(data.map.map);
}
