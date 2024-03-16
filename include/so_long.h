/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:56:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/16 15:39:34 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include "../minilibX/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define LEFT_ARROW_KEY 65361
# define UP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define DOWN_ARROW_KEY 65364
# define ESC_KEY 65307

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define IMG_SIZE 48
# define FAILURE 1
# define SUCCESS 0
# define ERR -1

# define BER_ERR "Argument is not a correct, please provide a .ber file.\n"
# define OTHER_ERR "At least one character of the map is not valid.\n"
# define CHARS_ERR "One of the characters \"0, 1, P, C, E\" is missing.\n"
# define PLAYER_ERR "This game is a solo campaign...\n"
# define PLAYERB_ERR "There can be only one player on each side...\n"
# define NOT_REC_ERR "The map is not a rectangle.\n"
# define EDGES_ERR "This map is not correct (The edges must be walls-1-)\n"
# define MULITPULE_EXITS_ERR "This map is invalid. it has multipule exits!\n"
# define MAP_NOT_SOLVABLE "This map is not solvable!\n"
# define TITTLE "so_long_game"

# define RED "\033[0;31m"
# define RESET "\033[0m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define PINK "\033[38;5;206m"
# define PEACH "\033[38;5;217m"
# define FOE "assets/foe.xpm"
# define PLAYER "assets/player.xpm"
# define EXIT "assets/chest_unlocked.xpm"
# define LOCKED "assets/chest_locked.xpm"
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define COIN1 "assets/coin/coin1.xpm"
# define COIN2 "assets/coin/coin2.xpm"
# define COIN3 "assets/coin/coin3.xpm"
# define COIN4 "assets/coin/coin4.xpm"
# define COIN5 "assets/coin/coin5.xpm"
# define W_TOP "assets/walls/wall_t.xpm"
# define W_BOT "assets/walls/wall_b.xpm"
# define W_LEFT "assets/walls/wall_l.xpm"
# define W_RIGHT "assets/walls/wall_r.xpm"
# define C_TL "assets/walls/corner_tl.xpm"
# define C_TL2 "assets/walls/corner_tl2.xpm"
# define C_TL3 "assets/walls/corner_tl3.xpm"
# define C_TR "assets/walls/corner_tr.xpm"
# define C_TR2 "assets/walls/corner_tr2.xpm"
# define C_TR3 "assets/walls/corner_tr3.xpm"
# define C_BL "assets/walls/corner_bl.xpm"
# define C_BL2 "assets/walls/corner_bl2.xpm"
# define C_BL3 "assets/walls/corner_bl3.xpm"
# define C_BR "assets/walls/corner_br.xpm"
# define C_BR2 "assets/walls/corner_br2.xpm"
# define C_BR3 "assets/walls/corner_br3.xpm"
# define W_RAND "assets/walls/wall_random.xpm"

typedef struct s_map
{
	char	**map;
	int		players_count;
	int		fd;
	int		exit_count;
	int		count_c;
	int		collected;
	int		line_count;
	char	*path;
	size_t	line_len;
	int		can_exit;
}			t_map;

typedef struct s_img
{
	void	*mxl_img;
	void	*wall;
	void	*ground;
	void	*player;
	void	*coin1;
	void	*exit_l;
	int		line_height;
	int		width;
	int		height;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		j;
	int		i;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
}			t_data;

typedef struct s_algo
{
	int		collectable;
	int		exit;
}			t_algo;

void		init_map(t_data *data);
void		create_map(t_data *data, char *path);
int			check_extention(char *path);
void		error_msg(char *str);
void		init_player(t_data *data);
void		ft_free(char **arr);
int			check_rectangle(t_data *data);
int			get_map_lines_num(char *path);
void		get_input_in_map(int row, size_t cloumn, int x, t_data *data);
char		*ft_strdup(char *s);
char		**map_copy(char **map);
t_algo		*algo_int(int collect_num);
void		player_pos(t_data *data);
int			map_path_checker(char **map, int i, int x, t_algo *algo);
int			return_res(t_data *data);
int			check_top_bottom(int row, char **map);
int			check_letters(t_data *data);
int			check_edges(int line_count, char **map);
int			check_map(t_data *data);
int			la_algo(t_data *data, int collect_num);
void		init_images(t_data *data);
int			init_window(t_data *data);
void		loop_images(t_data data);
void		destroy_images(t_data data);
void		parse_chars(t_data *data, int width, int i, int j);
int			render(t_data *data);
int			handle_btn_realease(t_data *data);
int			handle_keypress(int keysystem, t_data *data);
int			handle_resize(t_data *data);
void		move_msg(t_data *data);
void		move_player(t_data *data, char direction);
void		collect_coins(t_data *data, char direction);
int			win_game(t_data *data);
int			check_next_tile(t_data *data, char direction, char tile);

#endif
