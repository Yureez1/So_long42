/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:33 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/17 14:10:56 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.grid[x])
	{
		y = 0;
		while (data->map.grid[x][y])
		{
			if (data->map.grid[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			y++;
		}
		x++;
	}
	return (0);
}

