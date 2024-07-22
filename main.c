/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:07:41 by jbanchon          #+#    #+#             */
/*   Updated: 2024/07/22 17:46:37 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
}			data_game_img;

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
	
	int wall[1920][1080] = {0};

	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (y < map_width)
		{
			if(wall[x][y] == 1)
			{
				load_image(data->img, "./game_img/wall.xpm");
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, x, y );
			}
			x++;
		}
		y++;
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


int	main(void)
{
	data_game_img data;
	
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1920, 1080, "Map Parsing");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (EXIT_FAILURE);
	}
	map_parsing(&data, "./map1.ber");
	mlx_loop(data.mlx_ptr);
	return (0);
}
