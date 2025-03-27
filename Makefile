NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Kütüphane dizinleri
LIBFT_DIR = include/libft
MLX_DIR = include/minilibx

# Kütüphane dosyaları
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Bağlantı bayrakları
MLXFLAGS = -lXext -lX11 -lm
INCLUDES = -I./include -I./$(LIBFT_DIR) -I./$(MLX_DIR)

# Kaynak dosyaları
SRCS = src/main.c \
	   src/draw_fractal.c \
	   src/mouse_and_keys.c \
	   src/init.c \
	   src/julia.c \
	   src/mandelbrot.c \
	   src/utils.c \
	   src/tricorn_bonus.c

OBJS = $(SRCS:.c=.o)

all: lib_compile $(NAME)

# Kütüphaneleri derleme
lib_compile: $(LIBFT) $(MLX)

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(MLX):
	@make -C $(MLX_DIR) -s

# Ana programı derleme
$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean -s
	@make -C $(MLX_DIR) clean -s

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re lib_compile
