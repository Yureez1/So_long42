/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:35:10 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/28 16:43:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include "so_long_utils/so_long_utils.h"


int	load_textures(window_t *window)
{
	int width;
	int height;
	
	window->textures.game_img_wall = mlx_xpm_file_to_image(window->mlx_ptr,
			"/game_img/wall_img.xpm", &width, &height);
	window->textures.game_img_character = mlx_xpm_file_to_image(window->mlx_ptr,
			"/game_img/character.xpm", &width, &height);
	window->textures.game_img_exit = mlx_xpm_file_to_image(window->mlx_ptr,
			"/game_img/door.xpm", &width, &height);
	window->textures.game_img_floor = mlx_xpm_file_to_image(window->mlx_ptr,
			"/game_img/floor.xpm", &width, &height);
	window->textures.game_img_collectible = mlx_xpm_file_to_image(window->mlx_ptr,
			"/game_img/key.xpm", &width, &height);
	// window->textures.game_img_wall = mlx_xpm_file_to_image(window->mlx_ptr,
	//"enemy.xpm", &width, &height);
	if (load_textures_errors(window) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}

int	load_textures_errors(window_t *window)
{
	if (!window->textures.game_img_wall || !window->textures.game_img_floor
		|| !window->textures.game_img_character
		|| !window->textures.game_img_collectible
		|| !window->textures.game_img_exit || !window->textures.game_img_enemy)
		return (EXIT_FAILURE);
	return (0);
}

int	parse_map(const char *filename, map_parsing_t *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("maps/map1.ber", O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL && i < MAX_HEIGHT)
	{
		ft_strncpy(map->map[i], line, MAX_HEIGHT);
		map->map[i][ft_strnlen(line, MAX_WIDTH)] = '\0';
		i++;
		free(line);
	}
	map->height = i;
	close(fd);
	return (0);
}

void	render_map(window_t *window, map_parsing_t *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->map[x][y] == '1')
				mlx_put_image_to_window(window->mlx_ptr, window->mlx_win,
					window->textures.game_img_wall, y * 16, x * 16);
			else if (map->map[x][y] == '0')
				mlx_put_image_to_window(window->mlx_ptr, window->mlx_win,
					window->textures.game_img_floor, y * 16, x * 16);
			else if (map->map[x][y] == 'P')
				mlx_put_image_to_window(window->mlx_ptr, window->mlx_win,
					window->textures.game_img_character, y * 16, x * 16);
			else if (map->map[x][y] == 'E')
				mlx_put_image_to_window(window->mlx_ptr, window->mlx_win,
					window->textures.game_img_enemy, y * 16, x * 16);
			y++;
		}
		x++;
	}
}
