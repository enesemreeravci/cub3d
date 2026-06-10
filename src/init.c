/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:17:41 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/10 18:04:29 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *game)
{
	int	i;

	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->file = NULL;
	game->img.img = NULL;
	game->img.addr = NULL;
	i = 0;
	while (i < 4)
	{
		game->wall_tex[i].img = NULL;
		game->wall_tex[i].addr = NULL;
		game->wall_tex[i].width = 0;
		game->wall_tex[i].height = 0;
		i++;
	}
	game->tex.north = NULL;
	game->tex.south = NULL;
	game->tex.west = NULL;
	game->tex.east = NULL;
	game->floor.set = 0;
	game->ceiling.set = 0;
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}
