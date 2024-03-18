/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:20:04 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 10:19:36 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**map_copy(char **map);
t_algo	*algo_int(int collect_num);
void	player_pos(t_data *data);
int		map_path_checker(char **map, int i, int x, t_algo *algo);
int		la_algo(t_data *data, int collect_num);

char	**map_copy(char **map)
{
	int		x;
	char	**new_map;

	x = 0;
	while (map[x])
		x++;
	new_map = malloc(sizeof(char *) * (x + 1));
	if (!new_map)
		return (NULL);
	x = 0;
	while (map[x])
	{
		new_map[x] = ft_strdup(map[x]);
		x++;
	}
	new_map[x] = NULL;
	return (new_map);
}

t_algo	*algo_int(int collect_num)
{
	t_algo	*algo;

	algo = malloc(sizeof(*algo));
	if (!algo)
		return (NULL);
	algo->collectable = collect_num;
	algo->exit = 0;
	return (algo);
}

int	la_algo(t_data *data, int collect_num)
{
	int		res;
	char	**new_map;
	t_algo	*algo;

	algo = algo_int(collect_num);
	new_map = map_copy(data->map.map);
	player_pos(data);
	res = map_path_checker(new_map, data->i, data->j, algo);
	ft_free(new_map);
	free(algo);
	return (res);
}

void	player_pos(t_data *data)
{
	int	k;
	int	l;

	k = 0;
	while (data->map.map[k])
	{
		l = 0;
		while (data->map.map[k][l])
		{
			if (data->map.map[k][l] == 'P')
			{
				data->i = k;
				data->j = l;
				return ;
			}
			l++;
		}
		k++;
	}
}

int	map_path_checker(char **map, int i, int x, t_algo *algo)
{
	if (algo->collectable == 0 && algo->exit == 1)
		return (SUCCESS);
	if (map[i - 1][x] == 'E' || map[i + 1][x] == 'E')
		algo->exit = 1;
	else if (map[i][x - 1] == 'E' || map[i][x + 1] == 'E')
		algo->exit = 1;
	if (map[i][x] == 'C')
		algo->collectable -= 1;
	map[i][x] = '1';
	if (map[i - 1][x] != '1' && map[i - 1][x] != 'E')
		map_path_checker(map, (i - 1), x, algo);
	if (map[i + 1][x] != '1' && map[i + 1][x] != 'E')
		map_path_checker(map, (i + 1), x, algo);
	if (map[i][x - 1] != '1' && map[i][x - 1] != 'E')
		map_path_checker(map, i, (x - 1), algo);
	if (map[i][x + 1] != '1' && map[i][x + 1] != 'E')
		map_path_checker(map, i, (x + 1), algo);
	if (algo->collectable == 0 && algo->exit == 1)
		return (SUCCESS);
	else
		return (FAILURE);
}
