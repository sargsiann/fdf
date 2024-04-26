CC = cc

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

MINILIBX_FLAGS = -Lminilibx_macos -framework AppKit -framework OpenGl

LIBFT = $(MAKE) -C libft

GET_NEXT_LINE = $(MAKE) -C get_next_line

MLX = $(MAKE) -C minilibx_macos

SRC = main.c \
	$(shell find srcs -name '*.c') \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFT)
	$(GET_NEXT_LINE)
	$(MLX)
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) minilibx_macos/libmlx.a get_next_line/libgnl.a libft/libft.a $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(LIBFT) clean
	$(GET_NEXT_LINE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFT) fclean
	$(GET_NEXT_LINE) fclean
	$(MLX)  clean
re: fclean all

.PHONY: all clean fclean re