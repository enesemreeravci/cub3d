/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:16:05 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/09 16:27:29 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player(c));
}

static void	set_player_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

static void	handle_player(t_game *game, int x, int y, int *count)
{
	(*count)++;
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	set_player_direction(game, game->map[y][x]);
	game->map[y][x] = '0';
}

void	validate_map(t_game *game)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!is_valid_map_char(game->map[y][x]))
				error_exit_game(game, "Invalid character in map");
			if (is_player(game->map[y][x]))
				handle_player(game, x, y, &player_count);
			check_closed_cell(game, x, y);
			x++;
		}
		y++;
	}
	if (player_count != 1)
		error_exit_game(game, "Map must contain exactly one player");
}
