/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:31:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/07/23 14:05:37 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct data_game_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
}			data_game_t;

void		map_parsing(data_game_t *data, const char *file_path);
void		load_image(data_game_t *data, const char *file_path);
void		map_parsing_error(data_game_t *data);

#endif // SO_LONG