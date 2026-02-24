/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:15:07 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/12 16:34:47 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *so_long)
{
	return (!is_same_point(so_long->curr, so_long->next) \
		&& get_tile(so_long, so_long->next) != WALL);
}

void	move_player(t_game *so_long, t_map *map)
{
	static t_tile	previous = SPACE;

	map->tiles[so_long->curr.y][so_long->curr.x] = previous;
	if (get_tile(so_long, so_long->next) != COIN)
		previous = map->tiles[so_long->next.y][so_long->next.x];
	else
		previous = SPACE;
	map->tiles[so_long->next.y][so_long->next.x] = PLAYER;
	render_tile(so_long, (t_point){so_long->curr.x, so_long->curr.y});
	render_tile(so_long, (t_point){so_long->next.x, so_long->next.y});
	so_long->curr = so_long->next;
}

int	check_keypress(int key, t_game *so_long)
{
	if (key == 65307)
		quit_game(so_long);
	else if (key == 119)
		so_long->next = (t_point){so_long->curr.x, so_long->curr.y - 1};
	else if (key == 115)
		so_long->next = (t_point){so_long->curr.x, so_long->curr.y + 1};
	else if (key == 97)
		so_long->next = (t_point){so_long->curr.x - 1, so_long->curr.y};
	else if (key == 100)
		so_long->next = (t_point){so_long->curr.x + 1, so_long->curr.y};
	return (key);
}
