CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
SRC = $(shell find . -name '*.c')
LIBFT = ../../libft/libft.a
HEADERS = $(shell find . -name '*.h')

OBJ = $(SRC:.c=.o)
NAME = cube3d

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean

