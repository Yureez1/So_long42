/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:33 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/13 15:07:06 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.height)
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
	if (data->map.player_count != 1)
	{
		error_msg("Map must contain exactly one player.");
		exit(1);
	}
	return (0);
}
int	count_elements_in_map(char **grid, t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (grid[row][col] == 'P')
				data->map.player_count++;
			else if (grid[row][col] == 'E')
				data->map.exit_count++;
			else if (grid[row][col] == 'C')
				data->map.collectible_count++;
			col++;
		}
		row++;
	}
	if (!data->map.player_count || !data->map.exit_count
		|| !data->map.collectible_count)
		return (1);
	else
		return (0);
}
