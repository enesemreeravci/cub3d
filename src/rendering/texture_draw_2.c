/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:58:54 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/11 14:10:48 by eeravci          ###   ########.fr       */
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

static void	calc_wall_limits(t_ray *ray, t_tex_draw *draw)
{
	draw->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw->start_y = (WIN_HEIGHT - draw->line_height) / 2;
	draw->end_y = (WIN_HEIGHT + draw->line_height) / 2;
	if (draw->start_y < 0)
		draw->start_y = 0;
	if (draw->end_y >= WIN_HEIGHT)
		draw->end_y = WIN_HEIGHT - 1;
}

static void	calc_tex_x(t_game *game, t_ray *ray, t_tex_draw *draw)
{
	if (ray->side == 0)
		draw->wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		draw->wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	draw->wall_x -= floor(draw->wall_x);
	draw->tex_x = (int)(draw->wall_x * (double)draw->tex->width);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		draw->tex_x = draw->tex->width - draw->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		draw->tex_x = draw->tex->width - draw->tex_x - 1;
}

static void	draw_texture_pixels(t_game *game, t_ray *ray, t_tex_draw *draw,
		int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = draw->start_y;
	while (y <= draw->end_y)
	{
		tex_y = (int)draw->tex_pos;
		draw->tex_pos += draw->step;
		color = get_texture_pixel(draw->tex, draw->tex_x, tex_y);
		if (ray->side == 1)
			color = darken_color(color);
		put_pixel(game, x, y, color);
		y++;
	}
}

void	draw_textured_wall(t_game *game, t_ray *ray, int x)
{
	t_tex_draw	draw;

	draw.tex = &game->wall_tex[get_texture_index(ray)];
	calc_wall_limits(ray, &draw);
	calc_tex_x(game, ray, &draw);
	draw.step = 1.0 * draw.tex->height / draw.line_height;
	draw.tex_pos = (draw.start_y - WIN_HEIGHT / 2 + draw.line_height / 2)
		* draw.step;
	draw_texture_pixels(game, ray, &draw, x);
}
