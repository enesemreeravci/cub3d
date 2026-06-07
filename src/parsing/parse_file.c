/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:46:27 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '1' || line[i] == '0');
}

static void	validate_fields(t_game *game)
{
	if (!game->tex.north || !game->tex.south
		|| !game->tex.west || !game->tex.east)
		error_exit("Missing texture identifier(s)");
	if (!game->floor.set || !game->ceiling.set)
		error_exit("Missing floor or ceiling color");
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
			validate_fields(game);
			validate_map(game);
			return ;
		}
		error_exit("Invalid line in .cub file");
	}
	error_exit("No map found in .cub file");
}
