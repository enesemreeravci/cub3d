/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:56:09 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/09 15:52:26 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_textures(t_game *game)
{
	free(game->tex.north);
	free(game->tex.south);
	free(game->tex.west);
	free(game->tex.east);
}

void	free_game(t_game *game)
{
	free_textures(game);
	free_split(game->map);
	if (game->file)
		free_split(game->file);
}

void	cleanup_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->mlx && game->wall_tex[i].img)
			mlx_destroy_image(game->mlx, game->wall_tex[i].img);
		i++;
	}
	if (game->mlx && game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_game(game);
}

int	close_game(t_game *game)
{
	cleanup_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
