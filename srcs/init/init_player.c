/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:33 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/20 11:33:21 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.grid[y])
	{
		while (data->map.grid[y][x])
		{
			if (data->map.grid[y][x] == 'P')
			{
				data->player_y = y;
				data->player_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

