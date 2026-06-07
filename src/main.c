/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:27:36 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	return (ft_strncmp(file + len - 4, ".cub", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**file;

	if (argc != 2)
		error_exit("Usage: ./cub3D map.cub");
	if (!check_extension(argv[1]))
		error_exit("Map file must have .cub extension");
	init_game(&game);
	file = read_file(argv[1]);
	parse_file(&game, file);
	free_split(file);
	init_mlx(&game);
	mlx_loop(game.mlx);
	return (0);
}
