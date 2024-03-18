/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:58:06 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 10:24:34 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	parse_chars(t_data *data, int width, int i, int j);
int		render(t_data *data);

void	parse_chars(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, width, i
			* IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground, width, i
			* IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, width, i
			* IMG_SIZE);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_l, width, i
			* IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin1, width, i
			* IMG_SIZE);
}

int	render(t_data *data)
{
	int		i;
	int		width;
	size_t	j;

	if (data->win == NULL)
		return (FAILURE);
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		width = 0;
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			parse_chars(data, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
