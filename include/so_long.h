/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:31:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/07/22 17:23:03 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
}			data_game_img;

void		map_parsing(data_game_img *data, const char *file_path);
void		load_image(data_game_img *data, const char *file_path);
void		map_parsing_error(data_game_img *data);

#endif // SO_LONG