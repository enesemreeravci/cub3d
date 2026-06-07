/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:17:41 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->tex.north = NULL;
	game->tex.south = NULL;
	game->tex.west = NULL;
	game->tex.east = NULL;
	game->floor.set = 0;
	game->ceiling.set = 0;
	ft_bzero(game->tex_imgs, sizeof(game->tex_imgs));
	ft_bzero(&game->keys, sizeof(game->keys));
	ft_bzero(&game->player, sizeof(game->player));
	ft_bzero(&game->img, sizeof(game->img));
}
