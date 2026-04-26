NAME = cub3D	
CC = cc
CLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/init.c src/error.c src/parsing/read_file.c src/utils/free_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CLAGS) $(OBJ) -o $(NAME) -lm

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all