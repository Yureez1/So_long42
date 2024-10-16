/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:40 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/16 18:58:56 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_chars(t_data *data, int width, int x, int y)
{
	if (data->map.grid[x][y] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.wall, width, x * IMG_SIZE);
	else if (data->map.grid[x][y] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor, width, x * IMG_SIZE);
	else if (data->map.grid[x][y] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player, width, x * IMG_SIZE);
	else if (data->map.grid[x][y] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit, width, x * IMG_SIZE);
	else if (data->map.grid[x][y] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.collectible, width, x * IMG_SIZE);
}

int	render(t_data *data)
{
	int		x;
	size_t	y;
	int		width;

	if (data->win_ptr == NULL)
		return (1);
	x = 0;
	while (data->map.grid[x])
	{
		y = 0;
		width = 0;
		while (data->map.grid[x][y] && data->map.grid[x][y] != '\n')
		{
			parse_chars(data, width, x, y);
			width += IMG_SIZE;
			y++;
		}
		y = 0;
		width = 0;
		x++;
	}
	return (SUCCESS);
}
