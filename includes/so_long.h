#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "libft.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
**
Textures
**
*/
# define IMG_SIZE 64
# define WALL "assets/wall.xpm"
# define FLOOR "assets/floor.xpm"
# define KEY "assets/key.xpm"
# define PLAYER "assets/character.xpm"
# define EXIT "assets/door.xpm"
/*
**
Errors
**
*/
# define ERRORCHR "Error Char"
# define ERROR -1
# define FAILURE 1
# define SUCCESS 0
/*
**
Keys mouvements
**
*/
# define A 97
# define D 100
# define S 115
# define W 119
# define ARROW_TOP 65362
# define ARROW_BOT 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

/*
**
Colors
**
*/
# define RED "\033[1;31m"
# define GREY "\033[1;30m"
# define RESET "\033[0m"

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

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
	size_t		line_len;
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
	int			x;
	int			y;
	t_vector	player_pos;
	t_vector	map_size;
}				t_data;

// Game_init
void			ft_free(char **grid);
int				returned_line(char *filename);
void			set_input_map(int row, int fd, t_data *data);
int				allocate_map_rows(t_data *data);
int				create_map(char *filename, t_data *data);
void			init_map(t_data *data);
int				init_player(t_data *data);
int				count_elements_in_map(t_data *data);
void			print_map_dimensions(t_data *data);

// Errors
void			error_msg(char *message, t_data *data);
void			map_parameters(t_data *data);
int				check_map(t_data *data);
int				count_elements_in_map(t_data *data);
int				check_chars(t_data *data);
void			check_columns(t_data *data);
void			check_rows(t_data *data);
int				is_ber_file(const char *filename);

// Flood Fill
void			flood_fill(t_data *data, char **map_copy, t_vector pos);
void			ft_duplicate(t_data *data, char *filename);
void			ft_free_copy(t_data *data, char **map_copy);
void			copy_line(char *str, t_data *data, char **map_copy, int i);
void			ft_copy(t_data *data, char *filename, char **map_copy);

// Graphics
int				render(t_data *data);
void			render_background(t_data *data);
void			render_elements(t_data *data);
void			core_render(t_data *data);
int				load_images(t_data *data);
void			put_img(t_data *data, void *sprite, int x, int y);
void			images_loop(t_data *data);
void			destroy_image(t_data *data);
int				init_window(t_data *data);

// Events
void			player_mouv(t_data *data, int x_offset, int y_offset,
					char direction);
void			check_next_mouv(t_data *data, int x_offset, int y_offset);
int				handle_btnrelease(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				handle_resize(t_data *data);
void			can_exit(t_data *data);
int				print_count_step(t_data *data, char direction);

#endif