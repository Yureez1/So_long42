/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:37:47 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/17 12:20:56 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to load sprites
int	load_images(t_data *data)
{
	data->sprites.player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER,
			&(data->sprites.width), &(data->sprites.height));
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&(data->sprites.width), &(data->sprites.height));
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&(data->sprites.width), &(data->sprites.height));
	data->sprites.floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR,
			&(data->sprites.width), &(data->sprites.height));
	data->sprites.collectible = mlx_xpm_file_to_image(data->mlx_ptr, KEY,
			&(data->sprites.width), &(data->sprites.height));
	if (!data->sprites.player || !data->sprites.wall || !data->sprites.exit
		|| !data->sprites.floor || !data->sprites.collectible)
	{
		ft_printf("Error: Failed to load one or more textures");
		close_window(data);
		return (FAILURE);
	}
	return (SUCCESS);
}

char	*get_xpm_filename(int i)
{
	static char	*xpm_filename[] = {"assets/character.xpm", "assets/door.xpm",
		"assets/floor.xpm", "assets/key.xpm", "assets/wall.xpm"};

	return (xpm_filename[i]);
}

void	check_image_exist(t_data *data)
{
	int		i;
	int		fd;
	char	*filename;

	(void)data;
	i = 0;
	while (i < NUMBER_IMAGE)
	{
		filename = get_xpm_filename(i);
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			ft_printf("%s\n", filename);
			filename = NULL;
		}
		close(fd);
		i++;
	}
	filename = NULL;
}
