/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:50:52 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/17 13:20:59 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	push(t_stack *s, t_point p)
{
	if (s->top >= s->max - 1)
		return (0);
	s->data[++s->top] = p;
	return (1);
}

t_point	pop(t_stack *s)
{
	return (s->data[s->top--]);
}

static int	ff_process_tile(t_ff *ff, t_point p)
{
	if (p.x < 0 || p.y < 0 || p.x >= ff->map->cols || p.y >= ff->map->rows)
		return (0);
	if (ff->path[p.y][p.x] == WALL)
		return (0);
	if (ff->path[p.y][p.x] == COIN)
		ff->coins++;
	if (ff->path[p.y][p.x] == EXIT)
		ff->exit = 1;
	ff->path[p.y][p.x] = WALL;
	return (1);
}

static void	ff_push_neighbors(t_stack *s, t_point p)
{
	push(s, (t_point){p.x + 1, p.y});
	push(s, (t_point){p.x - 1, p.y});
	push(s, (t_point){p.x, p.y + 1});
	push(s, (t_point){p.x, p.y - 1});
}

int	flood_fill(t_map *map, t_point start, char **path)
{
	t_stack	s;
	t_point	p;
	t_ff	ff;

	s.data = malloc(sizeof(t_point) * map->rows * map->cols);
	if (!s.data)
		return (0);
	s.top = -1;
	s.max = map->rows * map->cols;
	push(&s, start);
	ff.map = map;
	ff.path = path;
	ff.coins = 0;
	ff.exit = 0;
	while (s.top >= 0)
	{
		p = pop(&s);
		if (!ff_process_tile(&ff, p))
			continue ;
		ff_push_neighbors(&s, p);
	}
	free(s.data);
	return (ff.coins == map->coins && ff.exit);
}
