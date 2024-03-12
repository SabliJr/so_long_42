/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:56:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/12 13:28:41 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
//# include "mlx.h"

#include <X11/Xlib.h>

# include "../libs/get_next_line/get_next_line.h"
# include "../libs/get_next_line/get_next_line_bonus.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"

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

# define IMG_SIZE 48

typedef struct s_map
{
	char	**map;
	int	players_count;
	int	fd;
	int	exit_count;
	int	count_c;
	int	collected;
	int	line_count;
	char	*path;
	size_t	line_len;
	int	can_exit;

} t_map;

typedef struct s_img
{
	void	*mxl_img;
	void	*wall;
	void	*ground;
	void	*player;
	void	*coin1;
	void	*exit_1;
	int		line_height;
	int		width;
	int 	height;
} t_img;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int	p_i;
	int	p_j;
	int	j;
	int	i;
	int	win_height;
	int	win_width;
	t_img img;
	t_map map;
} t_data;

// Paarsing the map;
void initiaize_map (t_data *data);
void	create_map(t_data *data, char *path);


#endif
