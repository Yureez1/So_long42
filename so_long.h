/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:31:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/28 14:34:31 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "so_long_utils/so_long_utils.h"
# include <X11/keysym.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100

typedef struct pos_s
{
	int x;
	int y;
}				pos_t;

typedef struct game_textures_s
{
	void	*game_img_wall;
	void	*game_img_floor;
	void	*game_img_character;
	void	*game_img_collectible;
	void	*game_img_exit;
	void	*game_img_enemy;
}				game_textures_t;

typedef struct map_parsing_s
{
	char map[MAX_HEIGHT][MAX_WIDTH];
	int width;
	int height;
	int player_x;
	int player_y;
	int exit_x;
	int exit_y;
}				map_parsing_t;

typedef struct window_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	game_textures_t textures;
}				window_t;

typedef struct data_player_move
{
	int					player_pos;
	int					player_pos_x;
	int					player_pos_y;
	pos_t				pos;
}						data_player_move_t;

int main(void);
int load_textures_errors(window_t *window);
int	load_textures(window_t *window);
int	parse_map(const char *filename, map_parsing_t *map);
void	render_map(window_t *window, map_parsing_t *map);


#endif // SO_LONG