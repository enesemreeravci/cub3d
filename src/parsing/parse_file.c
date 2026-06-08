/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:46:27 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/08 17:41:58 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


//Checks whether every required .cub element was parsed.
//The project needs four textures, one floor color, one ceiling color, and one map.

static void	check_required_elements(t_game *game)
{
	if (!game->tex.north || !game->tex.south || !game->tex.west || !game->tex.east)
		error_exit("Missing texture path");
	if (!game->floor.set)
		error_exit("Missing floor color");
	if (!game->ceiling.set)
		error_exit("Missing ceiling color");
	if (!game->map)
		error_exit("Missing map");
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
			validate_map(game);
			break ;
		}
		error_exit("Invalid line in .cub file");
	}
	check_required_elements(game);
}
