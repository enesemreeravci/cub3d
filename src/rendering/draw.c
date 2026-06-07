/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:03:11 by mafzal           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_draw	calc_draw(t_ray *ray)
{
	t_draw	d;

	d.height = (int)(WIN_H / ray->wall_dist);
	d.start = WIN_H / 2 - d.height / 2;
	if (d.start < 0)
		d.start = 0;
	d.end = WIN_H / 2 + d.height / 2;
	if (d.end >= WIN_H)
		d.end = WIN_H - 1;
	return (d);
}

static int	calc_tex_x(t_game *game, t_ray *ray)
{
	double	wall_x;
	int		tex_x;
	int		tex_w;

	if (ray->side == 0)
		wall_x = game->player.y + ray->wall_dist * ray->dir_y;
	else
		wall_x = game->player.x + ray->wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_w = game->tex_imgs[ray->tex_id].width;
	tex_x = (int)(wall_x * tex_w);
	if ((ray->side == 0 && ray->step_x > 0)
		|| (ray->side == 1 && ray->step_y < 0))
		tex_x = tex_w - tex_x - 1;
	return (tex_x);
}

static void	draw_ceiling(t_game *game, int x, int end)
{
	int	color;
	int	y;

	color = (game->ceiling.r << 16) | (game->ceiling.g << 8) | game->ceiling.b;
	y = 0;
	while (y < end)
	{
		img_pixel_put(&game->img, x, y, color);
		y++;
	}
}

static void	draw_floor(t_game *game, int x, int start)
{
	int	color;
	int	y;

	color = (game->floor.r << 16) | (game->floor.g << 8) | game->floor.b;
	y = start + 1;
	while (y < WIN_H)
	{
		img_pixel_put(&game->img, x, y, color);
		y++;
	}
}

static void	draw_wall_strip(t_game *game, t_ray *ray, int x, t_draw *d)
{
	t_tex_img	*tex;
	double		step;
	double		tex_pos;
	int			y;
	int			ty;

	tex = &game->tex_imgs[ray->tex_id];
	step = 1.0 * tex->height / d->height;
	tex_pos = (d->start - WIN_H / 2 + d->height / 2) * step;
	y = d->start;
	while (y <= d->end)
	{
		ty = (int)tex_pos;
		if (ty >= tex->height)
			ty = tex->height - 1;
		tex_pos += step;
		img_pixel_put(&game->img, x, y, get_tex_color(tex, d->tex_x, ty));
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_draw	d;

	if (ray->wall_dist < 0.0001)
		ray->wall_dist = 0.0001;
	d = calc_draw(ray);
	d.tex_x = calc_tex_x(game, ray);
	draw_ceiling(game, x, d.start);
	draw_wall_strip(game, ray, x, &d);
	draw_floor(game, x, d.end);
}
