/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:07:41 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/08 17:04:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct data_game_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_collectible;
	void	*img_floor;
}			data_game_t;

void		map_parsing_error(data_game_t *data);

void	load_image(void **img, data_game_t *data, const char *file_path)
{
	int	width;
	int	height;
	
	*img = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file_path, &width, &height);
	if(*img == NULL)
		exit(EXIT_FAILURE);
}

void	map_parsing(data_game_t *data, const char *file_path)
{
	int		x;
	int		tile_size;
	int		fd;
	char	*line;
	int		line_index;

	tile_size = 16;
	line_index = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		map_parsing_error(data);
	while ((line = get_next_line(fd)) != NULL)
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_floor, x *
				tile_size, line_index * tile_size);
			}
			else if (line[x] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->img_wall, x * tile_size, line_index * tile_size);
			}
			else if (line[x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->img_collectible, x * tile_size, line_index * tile_size);
			}
			x++;
		}
		free(line);
		line_index++;
	}
	close(fd);
}

void	map_parsing_error(data_game_t *data)
{
	if (data->img_wall != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
	if (data->img_collectible != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_collectible);
	if (data->img_floor != NULL)
		mlx_destroy_image(data->mlx_ptr, data-> img_floor);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(EXIT_FAILURE);
}

int	main(void)
{
	data_game_t	*data;

	data = malloc(sizeof(data_game_t));
	if (data == NULL)
		return (EXIT_FAILURE);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data);
		return (EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "Map Parsing");
	if (data->mlx_win == NULL)
	{
		free(data);
		return (EXIT_FAILURE);
	}
	load_image(&data->img_wall, data, "./game_img/wall.xpm");
	load_image(&data->img_collectible, data, "./game_img/key.xpm");
	load_image(&data->img_floor, data, "./game_img/floor.xpm");
	map_parsing(data, "./maps/map1.ber");
	mlx_loop(data->mlx_ptr);
	return (0);
}
