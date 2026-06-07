/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:40:11 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 15:45:11 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


//draws one vertical line at column x between start_Y and end_y
//this is the basic shape used later by raycasting to draw walls
void draw_vertical_line(t_game *game, int x, int start_y, int end_y)
{
    int y;

    if(x < 0 || x >= 800)
        return;
    if(start_y < 0)
        start_y = 0;
    if(end_y  >= 600)
        end_y = 599;
    y = start_y;

    while(y < end_y)
    {
        put_pixel(game, x, y, 0x00FFFFFF);
        y++;
    }
}

void render_test_lines(t_game *game)
{
    int x;
    int line_height;
    int start_y;
    int end_y;

    x = 0;
    while(x < 800)
    {
        line_height = 100 + ( x % 300);
        start_y = (600 - line_height) / 2;
        end_y = (600 + line_height) / 2;
        draw_vertical_line(game, x, start_y, end_y);
        x += 10;
    }
}