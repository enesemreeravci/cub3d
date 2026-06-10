/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:18:18 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/10 14:07:14 by eeravci          ###   ########.fr       */
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

int	parse_texture(t_game *game, char *line)
{
	char	*path;

	line = skip_spaces(line);
	if (!ft_strncmp(line, "NO ", 3))
	{
		path = skip_spaces(line + 2);
		set_texture(game, &game->tex.north, path);
		return (1);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		path = skip_spaces(line + 2);
		set_texture(game, &game->tex.south, path);
		return (1);
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		path = skip_spaces(line + 2);
		set_texture(game, &game->tex.west, path);
		return (1);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		path = skip_spaces(line + 2);
		set_texture(game, &game->tex.east, path);
		return (1);
	}
	return (0);
}
