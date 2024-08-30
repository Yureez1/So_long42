/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:31:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/29 22:22:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "so_long_utils/so_long_utils.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_HEIGHT 100
# define MAX_WIDTH 100

typedef struct pos_s
{
	int					x;
	int					y;
}						pos_t;

typedef struct game_textures_s
{
	void				*game_img_wall;
	void				*game_img_floor;
	void				*game_img_character;
	void				*game_img_collectible;
	void				*game_img_exit;
	void				*game_img_enemy;
}						game_textures_t;

typedef struct map_parsing_s
{
	char				map[MAX_HEIGHT][MAX_WIDTH];
	int					width;
	int					height;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
}						map_parsing_t;

typedef struct data_s
{
	void				*mlx_ptr;
	void				*mlx_win;
	game_textures_t		textures;
}						data_t;

typedef struct data_player_move
{
	int					x;
	int					y;
	pos_t				pos;
}						data_player_move_t;

typedef struct s_all_data
{
	data_t				*data;
	data_player_move_t	*player_mouv;
}						all_data_t;

#endif // SO_LONG