/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:08:09 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/17 13:17:45 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"

# define TILES "01CEP"
# define FW1 "textures/wall.xpm"
# define FS1 "textures/floor.xpm"
# define FC1 "textures/collectibles.xpm"
# define FE1 "textures/exit.xpm"
# define FP1 "textures/player.xpm"

typedef enum e_tile
{
	SPACE	= '0',
	WALL	= '1',
	COIN	= 'C',
	EXIT	= 'E',
	PLAYER	= 'P',
}			t_tile;

typedef enum e_index
{
	W1,
	S1,
	C1,
	E1,
	P1,
}		t_id;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}			t_point;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}			t_graphics;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

typedef struct s_map
{
	char			**tiles;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	coins;
	unsigned int	exits;
	unsigned int	players;
}			t_map;

typedef struct s_game
{
	t_map				*map;
	t_point				curr;
	t_point				next;
	t_graphics			display;
	t_sprite			*sp;
	unsigned int		coins;
	unsigned int		moves;
}					t_game;

typedef struct s_stack
{
	t_point	*data;
	int		top;
	int		max;
}	t_stack;

typedef struct s_ff
{
	t_map			*map;
	char			**path;
	unsigned int	coins;
	int				exit;
}	t_ff;

t_tile	get_tile(t_game *so_long, t_point p);
int		flood_fill(t_map *map, t_point start, char **path);
int		exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);
int		is_same_point(t_point a, t_point b);

void	clean_tiles(char **tiles);
void	clean_game(t_game *so_long);
int		quit_game(t_game *so_long);

int		check_format(t_map *map);
int		check_walls(t_map *map);
int		check_tiles(t_map *map, t_game *so_long);
int		check_paths(t_map *map, t_game *so_long);
int		check_screen_size(t_map *map);
void	check_map(t_game *so_long);
void	read_map(t_game *so_long, char *file);

void	init_mlx(t_game *so_long, t_map *map);
void	load_assets(t_game *so_long);
int		render_move(t_game *so_long);
void	render_tile(t_game *so_long, t_point p);
void	render_map(t_game *so_long, t_map *map);

void	move_player(t_game *so_long, t_map *map);
int		check_move(t_game *so_long);
int		check_keypress(int key, t_game *so_long);

#endif
