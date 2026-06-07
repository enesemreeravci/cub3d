/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:22:15 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/07 14:03:11 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_W 1280
# define WIN_H 720
# define TEX_N 0
# define TEX_S 1
# define TEX_E 2
# define TEX_W 3
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
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

typedef struct s_tex_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_tex_img;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	double		wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			tex_id;
}				t_ray;

typedef struct s_draw
{
	int			start;
	int			end;
	int			height;
	int			tex_x;
}				t_draw;

typedef struct s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
}				t_keys;

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
	t_tex_img	tex_imgs[4];
	t_keys		keys;
}				t_game;

void			init_game(t_game *game);
void			init_mlx(t_game *game);

int				error_exit(char *msg);

int				is_empty_line(char *line);
void			free_split(char **arr);

void			parse_file(t_game *game, char **file);
int				parse_texture(t_game *game, char *line);
char			**read_file(char *filename);
int				parse_color(t_game *game, char *line);
void			parse_map(t_game *game, char **file, int start);
void			validate_map(t_game *game);

char			get_cell(t_game *game, int x, int y);
void			check_closed_cell(t_game *game, int x, int y);

int				render_frame(t_game *game);
void			cast_ray(t_game *game, t_ray *ray, int x);
void			draw_column(t_game *game, t_ray *ray, int x);
void			load_textures(t_game *game);
void			img_pixel_put(t_img *img, int x, int y, int color);
int				get_tex_color(t_tex_img *tex, int tx, int ty);

int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);
int				close_window(t_game *game);
void			handle_movement(t_game *game);

#endif
