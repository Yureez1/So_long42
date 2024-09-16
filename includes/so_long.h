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
# define FAILURE 0
# define SUCCESS 1
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
int				count_elements_in_map(char **grid, t_data *data);
void			print_map_dimensions(t_data *data);

// Errors
void			error_msg(const char *message);
int				count_elements_in_map(char **grid, t_data *data);
int				check_top_bot(int row, char **grid);
int				check_edges(int line_count, char **grid);
int				check_rectangle(char **grid, int line_count);
int				check_map(t_data *data);

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
void	player_mouv(t_data *data, int keysym);
int	game_win(t_data *data);
void	collected_coins(t_data *data, int keysym);
int	check_next_mouv(t_data *data, int keysym, char tile);

int	handle_resize(t_data *data);

#endif