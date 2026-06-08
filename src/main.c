/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:27:36 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/08 17:55:59 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**file;

	if (argc != 2)
		error_exit("Usage: ./cub3D map.cub");
	check_extension(argv[1]);
	init_game(&game);
	file = read_file(argv[1]);
	parse_file(&game, file);
	free_split(file);
	init_mlx(&game);
	init_image(&game);
	load_textures(&game);
	render_frame(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
