/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:46:27 by eeravci           #+#    #+#             */
/*   Updated: 2026/04/28 15:54:24 by eeravci          ###   ########.fr       */
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

void	parse_file(t_game *game, char **file)
{
	int i;

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
	printf("NO: %s\n", game->tex.north);
	printf("SO: %s\n", game->tex.south);
	printf("WE: %s\n", game->tex.west);
	printf("EA: %s\n", game->tex.east);
	printf("F: %d,%d,%d\n", game->floor.r, game->floor.g, game->floor.b);
	printf("C: %d,%d,%d\n", game->ceiling.r, game->ceiling.g, game->ceiling.b);
	printf("Player position: x=%f y=%f\n", game->player.x, game->player.y);
	printf("Player direction: x=%f y=%f\n", game->player.dir_x,
		game->player.dir_y);
	print_map(game);
}