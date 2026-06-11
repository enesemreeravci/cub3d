/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:16:05 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/11 14:10:29 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player(c));
}

void	handle_player(t_game *game, int x, int y, int *count)
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
