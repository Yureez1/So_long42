/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/08 15:02:48 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_mouv(t_data *data, int x_offset, int y_offset, char direction)
{
	int new_x;
	int new_y;

	new_x = data->player_x + x_offset;
	new_y = data->player_y + y_offset;
	if (data->map.grid[new_y][new_x] == 'E' && data->map.collectible_count > 0)
		return;
	if (data->map.grid[new_y][new_x] == 'C')
	{
		data->map.collectible_count--;
		data->map.grid[new_y][new_x] = '0';
	}
	if (data->map.grid[new_y][new_x] == 'E' && data->map.collectible_count == 0)
	{
		destroy_image(data);
		ft_printf(RED"Good Job! You won with %d steps\n", data->count_step);
		exit(0);
	}
	if (data->map.grid[new_y][new_x] != '1')
	{
		data->map.grid[data->player_y][data->player_x] = '0';
		data->map.grid[new_y][new_x] = 'P';
		data->player_x = new_x;
		data->player_y = new_y;
		print_count_step(data, direction);
	}
}


