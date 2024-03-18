/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:33:26 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 10:21:38 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	error_msg(char *str, t_data *data)
{
	if (data->map.map)
		ft_free(data->map.map);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(1);
}
