/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:27:36 by eeravci           #+#    #+#             */
/*   Updated: 2026/04/28 15:54:08 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**file;

	if (argc != 2)
		error_exit("Usage: ./cub3D map.cub");
	init_game(&game);
	file = read_file(argv[1]);
	parse_file(&game, file);
	free_split(file);
	init_mlx(&game);
	mlx_loop(game.mlx);
	return (0);
}
