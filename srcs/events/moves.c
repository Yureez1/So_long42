/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/13 23:11:35 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collect_item(t_data *data, int new_x, int new_y)
{
	if (data->map.grid[new_y][new_x] == 'C')
	{
		data->map.collectible_count--;
		data->map.grid[new_y][new_x] = '0';
	}
}

void	check_exit(t_data *data, int new_x, int new_y)
{
	if (data->map.grid[new_y][new_x] == 'E' && data->map.collectible_count == 0)
	{
		destroy_image(data);
		ft_printf(RED "Good Job! You won with %d steps\n", data->count_step);
		exit(0);
	}
}

int move_player(t_data *data, int new_x, int new_y)
{
	if (data->map.grid[new_y][new_x] != '1')
	{
		if (data->map.grid[data->player_y][data->player_x] != 'E')
			data->map.grid[data->player_y][data->player_x] = '0';
		if (data->map.grid[new_y][new_x] != 'E')
			data->map.grid[new_y][new_x] = 'P';
		data->player_x = new_x;
		data->player_y = new_y;
		return (1);
	}
	return (0);
}


void	player_mouv(t_data *data, int x_offset, int y_offset, char direction)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + x_offset;
	new_y = data->player_y + y_offset;
	if (data->map.grid[new_y][new_x] == 'E')
		return ;
	collect_item(data, new_x, new_y);
	check_exit(data, new_x, new_y);
	if (move_player(data, new_x, new_y))
		print_count_step(data, direction);
}
