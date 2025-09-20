NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
INCLUDE = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c play_game.c open_texture.c basic_map.c keyboard_setting.c validate_map.c validate_map_player.c handle_error.c fill_the_map.c mem_allocate.c
OBJ = $(SRC:.c=.o)

SRC_PATHS = $(addprefix $(SRC_DIR)/,$(SRC))
OBJ_PATHS = $(addprefix $(OBJ_DIR)/,$(OBJ))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT_DIR) -Iminilibx-linux

MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

# --------------------- Rules ---------------------

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_PATHS) $(LIBFT)
	$(CC) $(OBJ_PATHS) -o $(NAME) $(MLX) $(LIBFT)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

