/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:40 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 18:16:59 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(t_data *data)
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
}
