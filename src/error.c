/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:53:48 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/09 15:43:51 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}
int	error_exit_game(t_game *game, char *msg)
{
	if (game)
		cleanup_game(game);
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
	return (1);
}
