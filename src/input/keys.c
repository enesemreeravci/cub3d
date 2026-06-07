/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:03:11 by mafzal           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
	else if (key == 119)
		game->keys.w = 1;
	else if (key == 115)
		game->keys.s = 1;
	else if (key == 97)
		game->keys.a = 1;
	else if (key == 100)
		game->keys.d = 1;
	else if (key == 65361)
		game->keys.left = 1;
	else if (key == 65363)
		game->keys.right = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
		game->keys.w = 0;
	else if (key == 115)
		game->keys.s = 0;
	else if (key == 97)
		game->keys.a = 0;
	else if (key == 100)
		game->keys.d = 0;
	else if (key == 65361)
		game->keys.left = 0;
	else if (key == 65363)
		game->keys.right = 0;
	return (0);
}
