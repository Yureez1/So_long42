/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:40 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/09 17:56:02 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.height)
	{
		y = 0;
		while (y < data->map.width)
		{
			if (data->map.grid[x][y] == '1')
				put_img(data, data->sprites.wall, y, x);
			else if (data->map.grid[x][y] == '0')
				put_img(data, data->sprites.floor, y, x);
			else if (data->map.grid[x][y] == 'P')
				put_img(data, data->sprites.player, y, x);
			else if (data->map.grid[x][y] == 'C')
				put_img(data, data->sprites.collectible, y, x);
			else if (data->map.grid[x][y] == 'E')
				put_img(data, data->sprites.exit, y, x);
			y++;
		}
		x++;
	}
	return (0);
}
void	put_img(t_data *data, void *img, int x, int y)
{
	int img_width = 16;
	int img_height = 16;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * img_width, y
		* img_height);
}
