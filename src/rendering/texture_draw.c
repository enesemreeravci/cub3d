/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:37:29 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/11 14:10:09 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
Selects which wall texture should be used based on ray hit direction.
 side == 0 means east/west wall, side == 1 means north/south wall.
*/

int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (ray->ray_dir_y > 0)
		return (TEX_NO);
	return (TEX_SO);
}
/*
Reads one pixel color from a loaded texture image.
 The texture image is stored as raw memory,
so we calculate the pixel address manually.
*/

int	get_texture_pixel(t_tex_img *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}
