/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:27:36 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 18:55:00 by eeravci          ###   ########.fr       */
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
	init_image(&game);
	render_background(&game);
	render_raycast(&game);
	put_pixel(&game, 400, 300, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
