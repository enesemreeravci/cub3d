NAME = cub3D	
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/main.c src/init.c src/error.c \
      src/parsing/read_file.c \
      src/parsing/parse_file.c \
      src/parsing/parse_texture.c \
      src/parsing/parse_color.c \
	  src/parsing/parse_map.c \
      src/utils/free_split.c \
      src/utils/string_utils.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all