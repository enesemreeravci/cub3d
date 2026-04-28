/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:32:00 by eeravci           #+#    #+#             */
/*   Updated: 2026/04/28 16:24:13 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	map_height(char **file, int start)
{
	int	height;

	height = 0;
	while (file[start + height])
	{
		if (is_empty_line(file[start + height]))
			break ;
		height++;
	}
	return (height);
}

static int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	parse_map(t_game *game, char **file, int start)
{
	int	i;
	int	height;

	height = map_height(file, start);
	if (height <= 0)
		error_exit("Missing map");
	game->map = malloc(sizeof(char *) * (height + 1));
	if (!game->map)
		error_exit("Malloc failed");
	game->map_height = height;
	game->map_width = 0;
	i = 0;
	while (i < height)
	{
		game->map[i] = ft_strdup(file[start + i]);
		if (line_len(game->map[i]) > game->map_width)
			game->map_width = line_len(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
}

void	print_map(t_game *game)
{
	int	i;

	printf("Map width: %d\n", game->map_width);
	printf("Map height: %d\n", game->map_height);
	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}
