# Compilateur et options
CC = cc
CFLAGS = -Werror -Wall -Wextra
MLX_DIR = /home/jbanchon/github/Cercle_2/So_long42/mlx
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
INCLUDES = -I$(MLX_DIR) -Iso_long42

# Répertoire des fichiers sources et objets
SRC_DIR = so_long42
OBJ_DIR = $(SRC_DIR)/obj

# Liste des fichiers sources
SOURCES = $(SRC_DIR)/main.c \
          $(SRC_DIR)/so_long_utils/get_next_line.c \
          $(SRC_DIR)/so_long_utils/get_next_line_utils.c

# Liste des fichiers objets
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Nom de l'exécutable
NAME = so_long

# Règle par défaut
all: $(NAME)

# Règle pour générer l'exécutable
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

# Règle pour compiler les fichiers .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJECTS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re

