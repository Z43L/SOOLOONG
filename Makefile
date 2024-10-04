NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I. -Ilib/LIBFT -Ilib/FT_PRINTF -Ilib/ft_get_next_line -Ilib/minilibx-linux

LIBFT_DIR = lib/LIBFT
PRINTF_DIR = lib/FT_PRINTF
#GNL_DIR = lib/ft_get_next_line
MLX_DIR = lib/minilibx-linux

SRCS = main.c game.c drawujo.c enemies.c game_utils.c map.c player.c comestibles.c
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libprintf.a
#GNL = $(GNL_DIR)/libgnl.a
MLX = $(MLX_DIR)/libmlx.a

all: subsystems $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

subsystems:
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	#make -C $(GNL_DIR)
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME) -lm -lbsd -lX11 -lXext -L$(MLX_DIR) -lmlx_Linux

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re subsystems
