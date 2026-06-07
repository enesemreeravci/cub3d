/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:03:11 by mafzal           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_ray(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / WIN_W - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1.0 / ray->dir_y);
}

static void	init_side_dist(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - game->player.x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - game->player.y) * ray->delta_y;
	}
}

static void	dda_loop(t_game *game, t_ray *ray)
{
	char	cell;

	cell = '0';
	while (cell != '1')
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		cell = get_cell(game, ray->map_x, ray->map_y);
	}
}

static void	set_tex_id(t_ray *ray)
{
	if (ray->side == 0 && ray->step_x > 0)
		ray->tex_id = TEX_E;
	else if (ray->side == 0 && ray->step_x < 0)
		ray->tex_id = TEX_W;
	else if (ray->side == 1 && ray->step_y > 0)
		ray->tex_id = TEX_S;
	else
		ray->tex_id = TEX_N;
}

void	cast_ray(t_game *game, t_ray *ray, int x)
{
	init_ray(game, ray, x);
	init_side_dist(game, ray);
	dda_loop(game, ray);
	if (ray->side == 0)
		ray->wall_dist = ray->side_x - ray->delta_x;
	else
		ray->wall_dist = ray->side_y - ray->delta_y;
	set_tex_id(ray);
}
