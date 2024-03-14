/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:56:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/13 14:56:01 by sabakar-         ###   ########.fr       */
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

//# define KEY_PRESS 2
//# define CLICK_CLOSE 17

# define KEY_W	119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define LEFT_ARROW_KEY 65361
# define UP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define DOWN_ARROW_KEY 65364
# define ESC_KEY 65307

# ifndef O_DIRECTORY
# define O_DIRECTORY 00200000
# endif

# define IMG_SIZE 48
# define FAILURE 1
# define SUCCESS 0

// Error messages
# define BER_ERR "Argument is not a correct .ber file.\n"
# define OTHER_ERR "At least one character of the map is not valid.\n"
# define CHARS_ERR "One of the characters \"0, 1, P, C, E\" is missing.\n"
# define PLAYER_ERR "This is a solo campaign...\n"
# define PLAYERB_ERR "There can be only one player on each side...\n"
# define NOT_REC_ERR "The map is not a rectangle.\n"
# define EDGES_ERR "The edges of the map are invalid (must be walls -1-)\n"

// Colors;
# define RED "\033[0;31m"
# define RESET "\033[0m"

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
void init_map (t_data *data);
void	create_map(t_data *data, char *path);

// Checking the map;
int check_extention(char *path);

void    error_msg(char *str, t_data *data);
void    init_player (t_data *data);
void ft_free(char **arr);
int get_map_lines_num (char *path);
void    get_input_in_map(int row, size_t cloumn, int x, t_data *data);
int check_map(t_data *data);
int check_recrtangel(t_data *data);
int check_edges(int line_count, char **map);
int check_letters(t_data *data);
int check_top_bottom(int row, char **map);
int check_extention(char *path);

#endif
