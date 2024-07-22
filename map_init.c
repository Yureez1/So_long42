/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:50:53 by jbanchon          #+#    #+#             */
/*   Updated: 2024/07/22 17:35:05 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	load_image(data_game_img *data, const char *file_path)
{
	int	width;
	int	height;

	data ->img = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file_path, &width,
			&height);
	if (data->img == NULL)
		exit(EXIT_FAILURE);
}

void	map_parsing(data_game_img *data, const char *file_path)
{
	int x;
	int y;
	int	map_width = 1920;
	int map_height = 1080;
	
	int wall[1080][1920] = {0};

	x = 0;
	while (x < map_width)
	{
		y = 0;
		while (y < map_height)
		{
			if(wall[x][y] == 1)
			{
				load_image(data, "./game_img/wall.xpm");
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, x, y );
			}
			y++;
		}
		x++;
	}
}

void	map_parsing_error(data_game_img *data)
{
	if(data->img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_display(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mlx_ptr);
	exit (EXIT_FAILURE);
}
