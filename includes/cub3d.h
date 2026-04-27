#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"

typedef struct s_texture
{
    char *north;
    char *south;
    char *west;
    char *east;
} t_texture;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int set;
} t_color;


typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int map_width;
    int map_weight;
    t_texture tex;
    t_color floor;
    t_color ceiling;
    t_player player;
} t_game;

void init_game(t_game *game);

//error
int error_exit(char *msg);


// utils
int is_empty_line(char *line);
void free_split(char **arr);

// parsing
void parse_file(t_game *game, char **file);
int parse_texture(t_game *game, char *line);
char **read_file(char *filename);
int	parse_color(t_game *game, char *line);

#endif
