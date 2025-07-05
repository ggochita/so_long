/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgi <giorgi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:00:42 by yourusernam       #+#    #+#             */
/*   Updated: 2024/05/08 14:55:09 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define ERROR -1
# define FAIL 0
# define OK 1
# define IMG_SIZE 32
# define NAME "SO_LONG"
# define PEACH "\033[38;5;217m"
# define RESET "\033[0m"
# define PLAYER "assets/player.xpm"
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define COIN "assets/coin.xpm"
# define EXIT "assets/exit.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	void	*coin;
}	t_img;

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		x;
	int		y;
	int		win_height;
	int		win_width;
	int		has_solution;
	int		coins_checked;
	t_img	img;
	t_map	map;
}	t_data;

typedef struct s_params
{
	t_data	*data;
	int		**visited;
	t_point	*queue;
	int		*rear;
	char	target;
}	t_params;

char	*ft_strcpy(char *dest, char *src);
char	**copy_map(char **src, int rows, size_t line_len);

void	error_msg(char *str);
void	exit_w_error(char *str, t_data *data, int exit_status);
void	ft_free(char **tab);
void	free_map(t_data *data);
void	fill_map(int row, t_data *data);
void	create_map(char *path, t_data *data);
void	map_init(t_data *data);
void	player_init(t_data *data);
void	images_init(t_data *data);
void	move_player(t_data *data, char direction);
void	loop_images(t_data *data);
void	destroy_images(t_data *data);
void	exit_game(t_data *data, int exit_status);
void	is_map_playable(t_data *data);
void	count_sym(char current, t_data *data);
void	is_enclosed(t_data *data, int x, int y);
void	free_visited_array(int **array, int rows);
void	clean_reach_res(t_params *params);
void	clean_game(t_data *data);
void	assign_sim(t_data **dest, t_data *src, int *coin_x, int *coin_y);

int		check_ber(char *path);
int		count_lines(char *path);
int		check_map(t_data *data);
int		window_init(t_data *data);
int		render(t_data *data);
int		handle_btnrelease(t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		is_reachable(t_data *data, int start_x, int start_y, char target);
int		find_coin(t_data *data, int *coin_x, int *coin_y);
int		**create_visited_array(int rows, int cols);
int		init_reach_res(t_params *params, t_data *data, char target, int *front);

#endif
