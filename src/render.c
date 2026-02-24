/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:10:02 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/17 13:17:04 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *so_long, t_map *map)
{
	so_long->display.mlx = mlx_init();
	if (!so_long->display.mlx)
		exit_error(so_long, "Failed to initialize mlx.");
	so_long->display.win = mlx_new_window(so_long->display.mlx, \
			map->cols * 32, map->rows * 32, "so_long");
	if (!so_long->display.win)
		exit_error(so_long, "Failed to create window.");
}

int	render_move(t_game *so_long)
{
	if (!check_move(so_long))
		return (0);
	ft_printf("Moves: %d\n", ++so_long->moves);
	if (get_tile(so_long, so_long->next) == COIN)
		so_long->coins++;
	else if (get_tile(so_long, so_long->next) == EXIT \
		&& so_long->coins == so_long->map->coins)
	{
		ft_printf("GG ! You win with %d moves.\n", so_long->moves);
		quit_game(so_long);
	}
	move_player(so_long, so_long->map);
	return (0);
}

void	render_tile(t_game *so_long, t_point p)
{
	t_sprite	sp;

	if (so_long->map->tiles[p.y][p.x] == WALL)
		sp = so_long->sp[W1];
	else if (so_long->map->tiles[p.y][p.x] == COIN)
		sp = so_long->sp[C1];
	else if (so_long->map->tiles[p.y][p.x] == EXIT)
		sp = so_long->sp[E1];
	else if (so_long->map->tiles[p.y][p.x] == SPACE)
		sp = so_long->sp[S1];
	else if (so_long->map->tiles[p.y][p.x] == PLAYER)
		sp = so_long->sp[P1];
	mlx_put_image_to_window(so_long->display.mlx, so_long->display.win, \
		sp.img, sp.width * p.x, sp.height * p.y);
}

void	render_map(t_game *so_long, t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
			render_tile(so_long, (t_point){x, y});
	}
}
