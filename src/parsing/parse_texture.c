/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:18:18 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/11 14:07:29 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*skip_spaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

static void	set_texture(t_game *game, char **target, char *path)
{
	if (*target)
		error_exit_game(game, "Duplicate texture identifier");
	*target = ft_strdup(path);
}

static int	parse_texture_line(t_game *game, char *line, char *id,
		char **target)
{
	char	*path;

	if (!ft_strncmp(line, id, 3))
	{
		path = skip_spaces(line + 2);
		set_texture(game, target, path);
		return (1);
	}
	return (0);
}

int	parse_texture(t_game *game, char *line)
{
	line = skip_spaces(line);
	if (parse_texture_line(game, line, "NO ", &game->tex.north))
		return (1);
	if (parse_texture_line(game, line, "SO ", &game->tex.south))
		return (1);
	if (parse_texture_line(game, line, "WE ", &game->tex.west))
		return (1);
	if (parse_texture_line(game, line, "EA ", &game->tex.east))
		return (1);
	return (0);
}
