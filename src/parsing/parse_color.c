/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:36:39 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/11 14:05:41 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*skip_spaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

static int	ft_atoi_simple(t_game *game, char **str)
{
	int	num;

	num = 0;
	if (**str < '0' || **str > '9')
		error_exit_game(game, "Invalid color value");
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	if (num < 0 || num > 255)
		error_exit_game(game, "Color value out of range");
	return (num);
}

static void	parse_rgb(t_game *game, char *str, t_color *color)
{
	str = skip_spaces(str);
	color->r = ft_atoi_simple(game, &str);
	if (*str++ != ',')
		error_exit_game(game, "Invalid RGB format");
	color->g = ft_atoi_simple(game, &str);
	if (*str++ != ',')
		error_exit_game(game, "Invalid RGB format");
	color->b = ft_atoi_simple(game, &str);
	str = skip_spaces(str);
	if (*str != '\0')
		error_exit_game(game, "Invalid extra characters in color");
	color->set = 1;
}

int	parse_color(t_game *game, char *line)
{
	line = skip_spaces(line);
	if (!ft_strncmp(line, "F ", 2))
	{
		if (game->floor.set)
			error_exit_game(game, "Duplicate floor color");
		parse_rgb(game, line + 1, &game->floor);
		return (1);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (game->ceiling.set)
			error_exit_game(game, "Duplicate ceiling color");
		parse_rgb(game, line + 1, &game->ceiling);
		return (1);
	}
	return (0);
}
