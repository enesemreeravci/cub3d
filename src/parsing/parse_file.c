/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:46:27 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/10 14:07:06 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	validate_map_end(t_game *game, char **file, int start)
{
	int	i;
	int	empty_found;

	i = start;
	empty_found = 0;
	while (file[i])
	{
		if (is_empty_line(file[i]))
			empty_found = 1;
		else if (empty_found)
			error_exit_game(game, "Invalid content after map");
		i++;
	}
}

// Checks whether every required .cub element was parsed.
// The project needs four textures,
// one floor color, one ceiling color, and one map.

static void	check_required_elements(t_game *game)
{
	if (!game->tex.north || !game->tex.south || !game->tex.west
		|| !game->tex.east)
		error_exit_game(game, "Missing texture path");
	if (!game->floor.set)
		error_exit_game(game, "Missing floor color");
	if (!game->ceiling.set)
		error_exit_game(game, "Missing ceiling color");
	if (!game->map)
		error_exit_game(game, "Missing map");
}

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '1' || line[i] == '0');
}

void	parse_file(t_game *game, char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (is_empty_line(file[i]))
		{
			i++;
			continue ;
		}
		if (parse_texture(game, file[i]) || parse_color(game, file[i]))
		{
			i++;
			continue ;
		}
		if (is_map_line(file[i]))
		{
			parse_map(game, file, i);
			validate_map_end(game, file, i);
			validate_map(game);
			break ;
		}
		error_exit_game(game, "Invalid line in .cub file");
	}
	check_required_elements(game);
}
