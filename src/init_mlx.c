/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:09:25 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/09 16:10:13 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("mlx_init failed");
}

void	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 800, 600, "cub3D");
	if (!game->win)
		error_exit_game(game, "mlx_new_window failed");
}
