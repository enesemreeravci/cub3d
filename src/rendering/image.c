/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:04:43 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 15:20:26 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// create an image buffer
// draw one pixel and put the image into the window

void	init_image(t_game *game)
{
    game->img.img = mlx_new_image(game->mlx, 800, 800);
    if(!game->img.img)
        error_exit("mlx_new_image failed");
    game->img.addr = mlx_get_data_addr(game->img.img,
    &game->img.bits_per_pixel,
    &game->img.line_length,
    &game->img.endian);
}

void put_pixel(t_game *game, int x, int y, int color)
{
    char *dst;

    if(x < 0 || x >= 800 || y < 0 || y >= 600)
        return;
    dst = game->img.addr + (y * game->img.line_length)
        + x * (game->img.bits_per_pixel / 8);
    *(unsigned int *)dst = color;
}