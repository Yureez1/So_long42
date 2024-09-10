#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define IMG_SIZE 32
# define WALL "assets/wall.xpm"
# define FLOOR "assets/floor.xpm"
# define KEY "assets/key.xpm"
# define PLAYER "assets/character.xpm"
# define EXIT "assets/door.xpm"

typedef struct s_sprites
{
	void		*player;
	void		*wall;
	void		*collectible;
	void		*exit;
	void		*floor;
	int			width;
	int			height;
}				t_sprites;

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

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_map		map;
	t_sprites	sprites;
	int			count_step;
	int			player_x;
	int			player_y;
	int			win_width;
	int			win_height;
	int			img_width;
	int			img_height;
	int			i;
	int			j;
}				t_data;

// Game_init
void			ft_free(char **grid);
int				returned_line(char *filename);
void			set_input_map(int row, int fd, t_data *data);
int				allocate_map_rows(t_data *data);
int				create_map(char *filename, t_data *data);
void			init_map(t_data *data);
int				init_player(t_data *data);
void			count_map_elements(t_data *data);
void			count_elements_in_map(char **grid, t_data *data);

// Errors
void			check_map(t_data *data);
void			check_map_walls(t_data *data);
void			error_msg(const char *message);

// Graphics
int				render(t_data *data);
void			render_background(t_data *data);
void			render_elements(t_data *data);
void			core_render(t_data *data);
int				load_images(t_data *data);
void			put_img(t_data *data, void *sprite, int x, int y);
void			images_loop(t_data *data);
void			destroy_image(t_data *data);

// Parsing

// Events

#endif