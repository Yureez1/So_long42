#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_SIZE 16

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	int			collected;
	int			can_exit;
	int			line_count;
}				t_map;

typedef struct	s_data;
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	t_map		map;
	int player_x;
	int player_y;
	int count_step;
	int win_width;
	int win_height;
	int img_width;
	int img_height;
}				t_data;
