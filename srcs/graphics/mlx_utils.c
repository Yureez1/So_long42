/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:43 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/16 17:36:025:55 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "So_long");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->win_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	destroy_image(t_data *data)
{
	if (data->sprites.player)
		mlx_destroy_image(data->mlx_ptr, data->sprites.player);
	if (data->sprites.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprites.wall);
	if (data->sprites.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit);
	if (data->sprites.floor)
		mlx_destroy_image(data->mlx_ptr, data->sprites.floor);
	if (data->sprites.collectible)
		mlx_destroy_image(data->mlx_ptr, data->sprites.collectible);
	if (data->map.grid)
		ft_free(data->map.grid);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
}

int	close_window(t_data *data)
{
	destroy_image(data);
	exit(0);
}

void	images_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, LeaveWindowMask, handle_btnrelease,
		data);
	mlx_hook(data->win_ptr, X_EVENT_KEY_EXIT, NoEventMask, close_window, data);
	mlx_loop(data->mlx_ptr);
}
