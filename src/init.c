#include "../includes/cub3d.h"

void init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->map = NULL;
    game->map_width = 0;
    game->map_height = 0;
    game->tex.north = NULL;
    game->tex.south = NULL;
    game->tex.west = NULL;
    game->tex.east = NULL;
    game->floor.set = 0;
    game->ceiling.set = 0;
}

