/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:27:36 by eeravci           #+#    #+#             */
/*   Updated: 2026/04/26 15:06:48 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**file;
	int		i;

	if (argc != 2)
		error_exit("Usage: ./cub3D map.cub");
	init_game(&game);
	file = read_file(argv[1]);

	i = 0;
	while (file[i])
	{
		printf("[%d] %s\n", i, file[i]);
		i++;
	}
	free_split(file);
	return (0);
}
