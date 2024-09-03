#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

typedef struct s_map
{
	char **grid;
	int width;
	int height;
	int player_count;
	int exit_count;
	int collectible_count;
}				t_map;

typedef struct s_data;
{
	void mlx_ptr;
}

