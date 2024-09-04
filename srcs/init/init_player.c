/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:33 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 17:28:30 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player(t_data *data)
{
	int x;
	int y;

	x = 0;
	while(x < data->map.height)
	{
		y = 0;
		while (y < data->map.width)
		{
			if (data->map.grid[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				data->map.player_count++;
			}
			y++;
		}
		x++;
	}
	if(data->map.player_count != 1)
	{
		error_msg("Map must contain exactly one player.");
		exit(1);
	}
}
