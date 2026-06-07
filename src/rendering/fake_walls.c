#include "../../includes/cub3d.h"

void render_fake_walls(t_game *game)
{
    int x;
    double distance;
    int line_height;
    int start_y;
    int end_y;

    x = 0;
    while(x < WIN_WIDTH)
    {
        distance = 1.0 +((double)x / WIN_WIDTH) * 4.0;
        line_height = (int)(WIN_HEIGHT / distance);
        start_y = (WIN_HEIGHT - line_height) / 2;
        end_y = (WIN_HEIGHT + line_height) / 2;
        draw_vertical_line(game, x, start_y, end_y);
        x++;
    }
}