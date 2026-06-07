#include "../../includes/cub3d.h"

static void free_textures(t_game *game)
{
    free(game->tex.north);
    free(game->tex.south);
    free(game->tex.west);
    free(game->tex.east);
}

void free_game(t_game *game)
{
    free_textures(game);
    free_split(game->map);
}

int close_game(t_game *game)
{
    if(game->img.img)
        mlx_destroy_image(game->mlx, game->img.img);
    if(game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    if(game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    free_game(game);
    exit(0);
    return (0);
}
