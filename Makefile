CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX42 = -L./MLX42/lib -lmlx42
GLFW  = -L$(HOME)/.brew/Cellar/glfw/3.4/lib -lglfw

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRC = \
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_lstadd_back_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_lstclear_bonus.c \
	libft/ft_lstdelone_bonus.c \
	libft/ft_lstiter_bonus.c \
	libft/ft_lstlast_bonus.c \
	libft/ft_lstmap_bonus.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstsize_bonus.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c
SRCS = \
	mandatory/parssing/check_colors.c \
	mandatory/parssing/check_map_valid.c \
	mandatory/parssing/check_texture.c \
	mandatory/parssing/check_wall.c \
	mandatory/parssing/fonction_test.c \
	mandatory/parssing/parsg.c \
	mandatory/parssing/parssing_final.c \
	mandatory/parssing/utils_00.c \
	mandatory/parssing/utils_01.c \
	mandatory/parssing/utils_02.c \
	mandatory/parssing/get_nextline_/get_next_line.c \
	mandatory/parssing/get_nextline_/get_next_line_utils.c \
	mandatory/rayCasting/Intersections.c \
	mandatory/rayCasting/hooks.c \
	mandatory/rayCasting/main.c \
	mandatory/rayCasting/movment.c \
	mandatory/rayCasting/rayCasting.c \
	mandatory/rayCasting/rendring.c \
	mandatory/rayCasting/textures.c \
	mandatory/rayCasting/utils.c \
	mandatory/rayCasting/utilsII.c \
	mandatory/rayCasting/utilsIII.c \
	mandatory/rayCasting/utilsIV.c


HEADERS = \
	mandatory/include/cube.h \
	mandatory/include/struct.h \
	mandatory/parssing/get_nextline_/get_next_line.h

OBJ = $(SRCS:.c=.o)

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

NAME = cube

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT): $(LIBFT_SRC) $(LIBFT_DIR)/libft.h
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(HEADERS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GLFW) $(MLX42) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
