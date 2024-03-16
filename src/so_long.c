/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:40:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/15 22:19:28 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int main()
int	main(int argc, char *argv[])
{
	// int argc = 2;
	// char *argv[3];

	// char *bs = "bullshit";
	// char *map = "../maps/invalid/invaild_width.ber";
	
	// argv[0] = bs;
	// argv[1] = map;
	// argv[2] = NULL;

	t_data data;
	if (argc != 2)
		return (ft_printf("\e[31mError\nPlease provide a valid map! \e0\n"));
	create_map(&data, argv[1]);
	init_map(&data);
	check_map(&data);
	init_player(&data);
}
