/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:56:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/07 14:15:34 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool>
# include "mlx.h"

#include <X11/Xlib.h>

# include "libs/get_next_line/get_next_line.h"
# include "libs/get_next_line/get_next_line_bonus.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/libft/libft.h"

# define KEY_PRESS 2
# define CLICK_CLOSE 17

# define KEY_W	119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define LEFT_ARROW_KEY 65361
# define UP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define DOWN_ARROW_KEY 65364
# define ESC_KEY 65307

typedef struct s_game
{
	char	**map;
	int	player_pos;
	int	img_size;
	int	error_flag;
	int	coins;
	int	raw_size;
	int	moves;
	int	num_of_raws;
	int	exit_num;
	int	players;

} t_game;

#endif
