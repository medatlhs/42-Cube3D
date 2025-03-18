CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42 = -L./MLX42/lib -lmlx42
GLFW  = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw

LIBFT = ./libft/libft.a
LIBFT_SRC = $(shell find ./libft -name '*.c')
SRCS = $(shell find ./mandatory/rayCasting -name '*.c') \
	   $(shell find ./get_next_line -name '*.c') \
       $(shell find ./mandatory/parssing -name '*.c')
HEADERS = $(shell find ./mandatory/include -name '*.h')

OBJ = $(SRCS:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
NAME = cube

all: $(NAME)

$(LIBFT): $(LIBFT_OBJ) ./libft/libft.h
		make -C ./libft

$(NAME): $(LIBFT) $(HEADERS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GLFW) $(MLX42) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
