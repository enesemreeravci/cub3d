NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I./includes -I$(MLX_DIR)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ../../so_long/minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = src/main.c \
      src/init.c \
      src/init_mlx.c \
      src/error.c \
      src/parsing/read_file.c \
      src/parsing/parse_file.c \
      src/parsing/parse_texture.c \
      src/parsing/parse_color.c \
      src/parsing/parse_map.c \
      src/parsing/validate_map.c \
      src/parsing/validate_map2.c \
      src/utils/free_split.c \
      src/utils/string_utils.c \
      src/rendering/image.c \
      src/rendering/texture.c \
      src/rendering/raycasting.c \
      src/rendering/draw.c \
      src/rendering/render.c \
      src/input/keys.c \
      src/input/movement.c

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
