/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:29:10 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/10 14:02:44 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Loads one XPM texture file into a MiniLibX image.
// The texture data address is saved so we can read pixels from it later.

static void	load_one_texture(t_game *game, t_tex_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		error_exit_game(game, "Failed to load texture");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
		error_exit_game(game, "Failed to get texture address");
}

// Loads all four wall textures from the parsed .cub configuration.
// The order is fixed: north, south, west, east.

void	load_textures(t_game *game)
{
	load_one_texture(game, &game->wall_tex[TEX_NO], game->tex.north);
	load_one_texture(game, &game->wall_tex[TEX_SO], game->tex.south);
	load_one_texture(game, &game->wall_tex[TEX_WE], game->tex.west);
	load_one_texture(game, &game->wall_tex[TEX_EA], game->tex.east);
}
