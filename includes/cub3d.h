/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:22:15 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/11 14:11:04 by eeravci          ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;

}				t_keys;
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

typedef struct s_tex_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_tex_img;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_tex_draw
{
	t_tex_img	*tex;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			line_height;
	int			start_y;
	int			end_y;
	int			tex_x;
}				t_tex_draw;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**file;
	int			map_width;
	int			map_height;
	t_texture	tex;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_img		img;
	t_tex_img	wall_tex[4];
	t_keys		keys;
}				t_game;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}				t_ray;

void			init_game(t_game *game);

// error
int				error_exit(char *msg);
int				error_exit_game(t_game *game, char *msg);
// utils
int				is_empty_line(char *line);
void			free_split(char **arr);
void			free_game(t_game *game);
int				close_game(t_game *game);
void			cleanup_game(t_game *game);
// parsing
void			parse_file(t_game *game, char **file);
int				parse_texture(t_game *game, char *line);
char			**read_file(char *filename);
int				parse_color(t_game *game, char *line);
void			parse_map(t_game *game, char **file, int start);
void			print_map(t_game *game);
void			validate_map(t_game *game);
void			check_extension(char *filename);
int				is_player(char c);
void			handle_player(t_game *game, int x, int y, int *count);
void			set_player_direction(t_game *game, char c);

// parsing/validate_map2.c
char			get_cell(t_game *game, int x, int y);
void			check_closed_cell(t_game *game, int x, int y);

// init_mlx
void			init_mlx(t_game *game);
void			init_window(t_game *game);
// rendering/image.c
void			init_image(t_game *game);
void			put_pixel(t_game *game, int x, int y, int color);

// rendering/draw.c
void			draw_vertical_line(t_game *game, int x, int start_y, int end_y);
void			render_test_lines(t_game *game);

// rendering/background.c
void			render_background(t_game *game);
int				rgb_to_int(int r, int g, int b);

// rendering raycast
void			render_fake_walls(t_game *game);
void			render_raycast(t_game *game);
void			init_ray(t_game *game, t_ray *ray, int x);
void			perform_dda(t_game *game, t_ray *ray);
void			render_frame(t_game *game);

// player
int				handle_key(int keycode, t_game *game);
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
void			load_textures(t_game *game);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				game_loop(t_game *game);

int				get_texture_index(t_ray *ray);
int				get_texture_pixel(t_tex_img *tex, int x, int y);
void			draw_textured_wall(t_game *game, t_ray *ray, int x);

#endif