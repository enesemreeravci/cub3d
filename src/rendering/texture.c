/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:03:11 by mafzal           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_one_texture(t_game *game, int id, char *path)
{
	t_tex_img	*t;

	t = &game->tex_imgs[id];
	t->img = mlx_xpm_file_to_image(game->mlx, path, &t->width, &t->height);
	if (!t->img)
		error_exit("Failed to load texture (check path)");
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->line_len, &t->endian);
	if (!t->addr)
		error_exit("Failed to get texture data");
}

void	load_textures(t_game *game)
{
	load_one_texture(game, TEX_N, game->tex.north);
	load_one_texture(game, TEX_S, game->tex.south);
	load_one_texture(game, TEX_E, game->tex.east);
	load_one_texture(game, TEX_W, game->tex.west);
}

int	get_tex_color(t_tex_img *tex, int tx, int ty)
{
	char	*pixel;

	if (tx < 0)
		tx = 0;
	if (tx >= tex->width)
		tx = tex->width - 1;
	if (ty < 0)
		ty = 0;
	if (ty >= tex->height)
		ty = tex->height - 1;
	pixel = tex->addr + ty * tex->line_len + tx * (tex->bpp / 8);
	return (*(int *)pixel);
}
