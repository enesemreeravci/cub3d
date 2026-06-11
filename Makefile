NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(LIBFT_DIR) -I./includes -I./minilibx-linux

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = src/main.c src/init.c src/init_mlx.c src/error.c \
      src/parsing/read_file.c \
      src/parsing/parse_file.c \
      src/parsing/parse_texture.c \
      src/parsing/parse_color.c \
      src/parsing/parse_map.c \
      src/parsing/validate_map.c \
      src/parsing/validate_map2.c \
      src/parsing/check_extension.c \
      src/parsing/player_direction.c \
      src/utils/free_split.c \
      src/utils/string_utils.c \
      src/utils/cleanup.c \
      src/rendering/image.c \
      src/rendering/draw.c \
      src/rendering/background.c \
      src/rendering/fake_walls.c \
      src/rendering/raycast.c \
      src/rendering/render_frame.c \
      src/rendering/textures.c \
      src/rendering/texture_draw.c \
      src/rendering/texture_draw_2.c \
      src/player/input.c \
      src/player/movement.c \
      src/player/rotation.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX_DIR)/libmlx.a
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re