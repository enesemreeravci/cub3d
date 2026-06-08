/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:22:02 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/08 17:55:50 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define MOVE_SPEED 0.003
#define COLLISION_BUFFER 0.20

//Checks whether a position is walkable with a small wall buffer.
//This prevents the player from getting too close to walls or clipping into corners.
static int	can_move_to(t_game *game, double x, double y)
{
	if (game->map[(int)(y - COLLISION_BUFFER)][(int)x] == '1')
		return (0);
	if (game->map[(int)(y + COLLISION_BUFFER)][(int)x] == '1')
		return (0);
	if (game->map[(int)y][(int)(x - COLLISION_BUFFER)] == '1')
		return (0);
	if (game->map[(int)y][(int)(x + COLLISION_BUFFER)] == '1')
		return (0);
	return (1);
}
//Moves the player forward in the direction they are currently facing.
//Before moving, it checks if the next map cell is not a wall.
void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
	if (can_move_to(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move_to(game, game->player.x, new_y))
		game->player.y = new_y;
}

//Moves the player backward opposite to the current facing direction.
//Wall checks prevent the player from walking through walls.
void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
	if (can_move_to(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move_to(game, game->player.x, new_y))
		game->player.y = new_y;
}


//Moves the player left, perpendicular to the facing direction.
//This is called strafing and uses the direction vector rotated 90 degrees.

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_x * MOVE_SPEED;
	if (can_move_to(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move_to(game, game->player.x, new_y))
		game->player.y = new_y;
}

//Moves the player right, perpendicular to the facing direction.
//This allows side movement without changing where the player is looking.

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_x * MOVE_SPEED;
	if (can_move_to(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move_to(game, game->player.x, new_y))
		game->player.y = new_y;
}


