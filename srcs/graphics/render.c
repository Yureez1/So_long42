/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:40 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/10 16:51:54 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_background(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map.grid[y] != NULL)
	{
		while (data->map.grid[y][i] != '\0')
		{
			if (data->map.grid[y][i] == '1')
				put_img(data, data->sprites.wall, i, y);
			else if (data->map.grid[y][i] == '0')
				put_img(data, data->sprites.floor, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

void	render_elements(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map.grid[y] != NULL)
	{
		while (data->map.grid[y][i])
		{
			if (data->map.grid[y][i] == 'C')
				put_img(data, data->sprites.collectible, i, y);
			else if (data->map.grid[y][i] == 'P')
				put_img(data, data->sprites.player, i, y);
			else if (data->map.grid[y][i] == 'E')
				put_img(data, data->sprites.exit, i ,y);
			i++;
		}
		i = 0;
		y++;
	}
}

int	render(t_data *data)
{
	render_background(data);
	render_elements(data);
	return (0);
}

void	core_render(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->win_width
				* data->img_width), (data->win_height * data->img_height),
			"So_long");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_loop(data->mlx_ptr);
}

void	put_img(t_data *data, void *img, int x, int y)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * img_width, y
		* img_height);
}
