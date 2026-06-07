/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:22:15 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 15:39:29 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_texture;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			set;
}				t_color;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	t_texture	tex;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_img		img;
}				t_game;

void			init_game(t_game *game);

// error
int				error_exit(char *msg);

// utils
int				is_empty_line(char *line);
void			free_split(char **arr);
void free_game(t_game *game);
int close_game(t_game *game);
// parsing
void			parse_file(t_game *game, char **file);
int				parse_texture(t_game *game, char *line);
char			**read_file(char *filename);
int				parse_color(t_game *game, char *line);
void			parse_map(t_game *game, char **file, int start);
void			print_map(t_game *game);
void			validate_map(t_game *game);

// parsing/validate_map2.c
char			get_cell(t_game *game, int x, int y);
void			check_closed_cell(t_game *game, int x, int y);

// init_mlx
void			init_mlx(t_game *game);

// rendering/image.c
void			init_image(t_game *game);
void			put_pixel(t_game *game, int x, int y, int color);

// rendering/draw.c
void draw_vertical_line(t_game *game, int x, int start_y, int end_y);
void render_test_lines(t_game *game);

#endif