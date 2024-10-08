NAME = so_long

# Compilation and options
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

# Path to directories
SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = includes
MLX_DIR = /home/jbanchon/github/Cercle_2/so_long42/mlx
LIBFT_DIR = /home/jbanchon/github/Cercle_2/so_long42/libft
FT_PRINTF_DIR = /home/jbanchon/github/Cercle_2/so_long42/ft_printf

# Sources files
SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
	$(wildcard $(LIBFT_DIR)/*.c) \
	$(wildcard $(SRC_DIR)/init/*.c) \
	$(wildcard $(SRC_DIR)/parsing/*.c) \
	$(wildcard $(SRC_DIR)/errors/*.c) \
	$(wildcard $(SRC_DIR)/graphics/*.c) \
	$(wildcard $(SRC_DIR)/events/*.c) \
	$(SRC_DIR)/main.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

# Objects files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Options for MLX
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
INCLUDES = -Iincludes -I$(MLX_DIR) -Iget_next_line -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

# Default setting
all: $(NAME)

# Final compilation program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

# Compilation objects files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning objects files
clean:
	rm -rf $(OBJ_DIR)

# Cleaning all
fclean: clean
	rm -f $(NAME)

# Rebuilding all
re: fclean all

.PHONY: all clean fclean re