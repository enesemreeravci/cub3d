/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:03:11 by mafzal           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player(t_game *game, double dx, double dy)
{
	t_player	*p;

	p = &game->player;
	if (get_cell(game, (int)(p->x + dx), (int)p->y) != '1')
		p->x += dx;
	if (get_cell(game, (int)p->x, (int)(p->y + dy)) != '1')
		p->y += dy;
}

static void	move_forward_back(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (game->keys.w)
		move_player(game, p->dir_x * MOVE_SPEED, p->dir_y * MOVE_SPEED);
	if (game->keys.s)
		move_player(game, -p->dir_x * MOVE_SPEED, -p->dir_y * MOVE_SPEED);
}

static void	strafe(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (game->keys.a)
		move_player(game, -p->dir_y * MOVE_SPEED, p->dir_x * MOVE_SPEED);
	if (game->keys.d)
		move_player(game, p->dir_y * MOVE_SPEED, -p->dir_x * MOVE_SPEED);
}

static void	rotate_player(t_game *game, double angle)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &game->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	handle_movement(t_game *game)
{
	move_forward_back(game);
	strafe(game);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
}
