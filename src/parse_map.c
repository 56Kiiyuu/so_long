/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:16:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/16 11:50:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(t_map *map)
{
	unsigned int	i;
	unsigned int	first_row_len;

	i = 0;
	first_row_len = ft_strlen(map->tiles[0]);
	while (i < map->rows)
	{
		if (ft_strlen(map->tiles[i++]) != first_row_len)
			return (0);
	}
	map->cols = first_row_len;
	return (1);
}

int	check_walls(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (++i < map->rows)
		if (map->tiles[i][0] != WALL || map->tiles[i][map->cols - 1] != WALL)
			return (0);
	i = -1;
	while (++i < map->cols)
		if (map->tiles[0][i] != WALL || map->tiles[map->rows - 1][i] != WALL)
			return (0);
	return (1);
}

int	check_tiles(t_map *map, t_game *so_long)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->tiles[i][j] == PLAYER)
			{
				map->players++;
				so_long->curr = (t_point){j, i};
				so_long->next = so_long->curr;
			}
			else if (map->tiles[i][j] == EXIT)
				map->exits++;
			else if (map->tiles[i][j] == COIN)
				map->coins++;
			else if (!ft_strchr(TILES, map->tiles[i][j]))
				return (0);
		}
	}
	return (map->players == 1 && map->exits == 1 && map->coins >= 1);
}

int	check_paths(t_map *map, t_game *so_long)
{
	unsigned int	i;
	int				reach_exit;
	char			**tiles;

	i = -1;
	reach_exit = 0;
	tiles = ft_calloc(map->rows + 1, sizeof(char *));
	if (!tiles)
		exit_error(so_long, "Malloc failed.");
	while (++i < map->rows)
	{
		tiles[i] = ft_strdup(map->tiles[i]);
		{
			if (!tiles[i])
			{
				clean_tiles(tiles);
				exit_error(so_long, "Malloc failed.");
			}
		}
	}
	reach_exit = flood_fill(map, so_long->curr, tiles);
	clean_tiles(tiles);
	return (reach_exit);
}

int	check_screen_size(t_map *map)
{
	if ((int)(map->cols * 32) > 1920)
		return (0);
	if ((int)(map->rows * 32) > 1080)
		return (0);
	return (1);
}
