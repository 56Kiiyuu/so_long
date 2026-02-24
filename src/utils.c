/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:02:38 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/17 12:51:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	get_tile(t_game *so_long, t_point p)
{
	return (so_long->map->tiles[p.y][p.x]);
}

int	is_same_point(t_point a, t_point b)
{
	return (a.x == b.x && a.y == b.y);
}

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	check_filename(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (!ft_strnstr((file + i - 4), ".ber", 4))
		exit_error(NULL, "Invalid file extension.");
}
