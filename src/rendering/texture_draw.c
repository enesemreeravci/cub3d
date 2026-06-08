/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:37:29 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/08 17:12:54 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	darken_color(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r /= 2;
	g /= 2;
	b /= 2;
	return ((r << 16) | (g << 8) | b);
}

//Selects which wall texture should be used based on ray hit direction.
//side == 0 means east/west wall, side == 1 means north/south wall.

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


//Reads one pixel color from a loaded texture image.
//The texture image is stored as raw memory, so we calculate the pixel address manually.

int	get_texture_pixel(t_tex_img *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_length
			+ x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}


//Draws one textured vertical wall slice.
//It calculates which texture column was hit, then maps that texture column onto the wall height.
void	draw_textured_wall(t_game *game, t_ray *ray, int x)
{
	t_tex_img	*tex;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			line_height;
	int			start_y;
	int			end_y;
	int			tex_x;
	int			tex_y;
	int			y;
	int			color;

	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	start_y = (WIN_HEIGHT - line_height) / 2;
	end_y = (WIN_HEIGHT + line_height) / 2;
	if (start_y < 0)
		start_y = 0;
	if (end_y >= WIN_HEIGHT)
		end_y = WIN_HEIGHT - 1;

	tex = &game->wall_tex[get_texture_index(ray)];

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);

	tex_x = (int)(wall_x * (double)tex->width);

	if (ray->side == 0 && ray->ray_dir_x < 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		tex_x = tex->width - tex_x - 1;

	step = 1.0 * tex->height / line_height;
	tex_pos = (start_y - WIN_HEIGHT / 2 + line_height / 2) * step;

	y = start_y;
	while (y <= end_y)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color = get_texture_pixel(tex, tex_x, tex_y);
		if (ray->side == 1)
			color = darken_color(color);
		put_pixel(game, x, y, color);
		y++;
	}
}
