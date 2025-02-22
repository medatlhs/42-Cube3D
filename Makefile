CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
MLX42 = -L$(HOME)/my_libraries/MLX42/lib -lmlx42
GLFW  = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw
LIBFT = ./libft/libft.a
SRC = $(shell find ./mandatory/src -name '*.c')
HEADERS = $(shell find ./mandatory/include/ -name '*.h')

OBJ = $(SRC:.c=.o)
NAME = cube

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) $(GLFW) $(MLX42) $(LIBFT)  -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean

