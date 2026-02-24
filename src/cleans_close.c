/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleans_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:35:05 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/17 13:11:04 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_tiles(char **tiles)
{
	size_t	i;

	i = 0;
	if (!tiles)
		return ;
	while (tiles[i])
		free (tiles[i++]);
	free (tiles);
}

void	clean_map(t_map *map)
{
	if (!map)
		return ;
	clean_tiles(map->tiles);
	free (map);
}

void	clean_sprites(t_game *so_long)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (so_long->sp[i].img)
			mlx_destroy_image(so_long->display.mlx, so_long->sp[i].img);
		i++;
	}
	free (so_long->sp);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long->map);
	if (so_long->sp)
		clean_sprites(so_long);
	if (so_long->display.win)
		mlx_destroy_window(so_long->display.mlx, so_long->display.win);
	if (so_long->display.mlx)
		mlx_destroy_display(so_long->display.mlx);
	free(so_long->display.mlx);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(0);
}
