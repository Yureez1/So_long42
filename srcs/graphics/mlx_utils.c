/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:43 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/09 17:49:39 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to initialize the window
int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_msg("Failed to initialize MLX");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "so_long");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
// Function to load sprites
int	load_images(t_data *data)
{
	data->sprites.player = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER, &data->sprites.width, &data->sprites.height);
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&data->sprites.width, &data->sprites.height);

	data->sprites.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->sprites.width, &data->sprites.height);
	data->sprites.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			FLOOR, &data->sprites.width, &data->sprites.height);
	data->sprites.collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			KEY, &data->sprites.width, &data->sprites.height);
	return (EXIT_SUCCESS);
}

void	destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprites.player);
	mlx_destroy_image(data->mlx_ptr, data->sprites.wall);
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit);
	mlx_destroy_image(data->mlx_ptr, data->sprites.floor);
	mlx_destroy_image(data->mlx_ptr, data->sprites.collectible);
	mlx_destroy_display(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
}

void	images_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, render_map, &data);
	// mlx_hook(data.win, Keypress, KeyPressMask, &handle_keypress, &data);
	// mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btnrelease, &data;
	mlx_loop(data->mlx_ptr);
}
