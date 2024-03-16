/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:40:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/16 14:12:34 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int main()
int	main(int argc, char *argv[])
{
	t_data	data;
	// void	*mlx;
	// void	*win;

	// int argc = 2;
	// char *argv[3];
	// char *bs = "bullshit";
	// char *map = "../maps/invalid/invaild_width.ber";
	// argv[0] = bs;
	// argv[1] = map;
	// argv[2] = NULL;
	if (argc != 2)
		return (ft_printf("\e[31mError\nPlease provide a valid map! \e0\n"));
	create_map(&data, argv[1]);
	init_map(&data);
	check_map(&data);
	init_player(&data);
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 800, 600, "My first window");
	init_window(&data);
	ft_printf("We are heere!\n");
	ft_printf("We are here!\n");
	init_images(&data);
	ft_printf("We are heere after the images!\n");

	//  mlx_key_hook(win, handle_input, NULL);
     //create also an clean_up hook
     //i.e. press ESC will call all the destroy functions 


    // Wait for events.
    //  mlx_loop(mlx);
	render(&data);
	loop_images(data);
	// destroy_images(data);
}
