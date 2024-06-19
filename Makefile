NAME = fdf

CC = cc 

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -I MLX_FLAGS

CFLAGS = -Wall -Wextra -Werror

MATH_FLAG = -lm

SRCS = $(shell find srcs -name "*.c")

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

DEPS = Makefile $(shell find includes -name "*.h")

MLX_MAKE = $(MAKE) -C mlx

MLX_CLEAN = $(MAKE) -C mlx clean

all : $(NAME)

$(NAME) : $(OBJS) $(DEPS)
	$(MLX_MAKE)
	$(CC) $(OBJS) $(CFLAGS) $(MATH_FLAG) -fsanitize=address mlx/libmlx.a $(MLX_FLAGS) -I includes -o fdf

clean : 
	rm -rf $(OBJS)
	$(MLX_CLEAN)

fclean : clean
	rm fdf
	rm mlx/libmlx.a

re : fclean all

.PHONY : all clean fclean re