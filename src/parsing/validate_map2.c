/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:32:24 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_cell(t_game *game, int x, int y)
{
	int	len;

	if (y < 0 || y >= game->map_height)
		return (' ');
	if (x < 0)
		return (' ');
	len = 0;
	while (game->map[y][len])
		len++;
	if (x >= len)
		return (' ');
	return (game->map[y][x]);
}

void	check_closed_cell(t_game *game, int x, int y)
{
	if (get_cell(game, x, y) != '0')
		return ;
	if (get_cell(game, x + 1, y) == ' ' || get_cell(game, x - 1, y) == ' '
		|| get_cell(game, x, y + 1) == ' ' || get_cell(game, x, y - 1) == ' ')
		error_exit("Map is not closed by walls");
}
