NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_MAC_FLAGS = -Lminilibx_macos -framework OpenGl -framework AppKit

MATH_FLAG = -lm

MLX_MAKE = $(MAKE) -C minilibx_macos 

LIBFT_MAKE = $(MAKE) -C libft

SRCS = $(shell find srcs gnl -name "*.c")

OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME): $(OBJS) 
	$(LIBFT_MAKE) 
	$(MLX_MAKE) 
	$(CC) $(OBJS) $(CFLAGS) $(MATH_FLAG) $(MLX_MAC_FLAGS) minilibx_macos/libmlx.a libft/libft.a -o $(NAME)

clean : 
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx_macos clean
	rm -rf $(OBJS) 

fclean : clean 
	rm -rf libft/libft.a 
	rm -rf $(NAME) 
	rm -rf minilib_macos/libmlx.a 

re : fclean all

.PHONY = all clean fclean re