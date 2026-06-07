#include "../../includes/cub3d.h"


//initializes ray values for one screen column.
//each column has its own ray direction based on player direction and camera plane.

void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x
		+ game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y
		+ game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}
//Chooses ray step direction and initial side distances.
//This prepares the ray to move through the map grid using DDA.
static void	init_ray_steps(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* ray->delta_dist_y;
	}
}
//Runs the DDA algorithm until the ray hits a wall.
//DDA moves from grid cell to grid cell efficiently instead of checking every pixel.
void	perform_dda(t_game *game, t_ray *ray)
{
	init_ray_steps(game, ray);
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

//Casts one ray for each screen column and draws a wall slice.
//This is the first real 3D render using the map and player direction.
void	render_raycast(t_game *game)
{
	int		x;
	t_ray	ray;
	int		line_height;
	int		start_y;
	int		end_y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game, &ray, x);
		perform_dda(game, &ray);
		line_height = (int)(WIN_HEIGHT / ray.perp_wall_dist);
		start_y = (WIN_HEIGHT - line_height) / 2;
		end_y = (WIN_HEIGHT + line_height) / 2;
		draw_vertical_line(game, x, start_y, end_y);
		x++;
	}
}