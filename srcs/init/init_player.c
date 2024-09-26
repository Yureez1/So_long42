/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:33 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/26 12:28:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			printf("Checking position (%d, %d): %c\n", x, y, data->map.grid[y][x]);
			if (data->map.grid[y][x] == 'P')
			{
				data->player_pos.x = x;
				data->player_pos.y = y;
				printf("Found player at (%d, %d)\n", x, y);
				return (0);
			}
			x++;
		}
		y++;
	}
	fprintf(stderr, "Error: Player position not found in the map.\n");
	return (-1);
}

