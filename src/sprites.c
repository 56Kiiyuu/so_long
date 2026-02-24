/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:12:59 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/17 13:21:14 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_sprite(t_game *so_long, int id, char *path)
{
	so_long->sp[id].img = mlx_xpm_file_to_image(so_long->display.mlx, path,
			&so_long->sp[id].width, &so_long->sp[id].height);
	if (!so_long->sp[id].img)
	{
		exit_error(so_long, "Failed to load texture");
		quit_game(so_long);
		exit(EXIT_FAILURE);
	}
}

static void	init_sprites(t_game *so_long)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		so_long->sp[i].img = NULL;
		i++;
	}
}

void	load_assets(t_game *so_long)
{
	so_long->sp = malloc(5 * sizeof(t_sprite));
	if (!so_long->sp)
		exit_error(so_long, "Malloc sprites");
	init_sprites(so_long);
	load_sprite(so_long, W1, FW1);
	load_sprite(so_long, S1, FS1);
	load_sprite(so_long, C1, FC1);
	load_sprite(so_long, E1, FE1);
	load_sprite(so_long, P1, FP1);
}
