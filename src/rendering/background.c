#include "../../includes/cub3d.h"

// converts rgb values into a single integer color
// minilbx expect colors packed into one integer

int rgb_to_int(int r, int g, int b)
{
    return((r << 16) | (g << 8) | b);
}

// draws the ceiling and floor color across the entire screen
// this forms the background before walls are rendered
void render_background(t_game *game)
{
    int x;
    int y;
    int ceiling_color;
    int floor_color;

    ceiling_color = rgb_to_int(game->ceiling.r,
            game->ceiling.g,
            game->ceiling.b);
    
    floor_color = rgb_to_int(game->floor.r,
            game->floor.g, 
            game->floor.b);
    y = 0;
    while(y < 600)
    {
        x = 0;
        while(x < 800)
        {
            if( y  < 300)
                put_pixel(game, x, y, ceiling_color);
            else
                put_pixel(game, x, y, floor_color);
            x++;
        }
        y++;
    }
}