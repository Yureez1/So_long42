/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:56 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 17:29:21 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_data *data)
{
	check_map_walls(data);
	if(data->map.collectible_count < 1)
		error_msg("The map must have at least one colletible");
	if(data->map.exit_count != 1)
		error_msg("The map must have exactly one exit");
	if(data->map.player_count != 1)
		error_msg("The map must have exactly one player");
}

void check_map_walls(t_data *data)
{
	int i;
	int last_row;
	int last_col;
	
	last_row = data->map.height - 1;
	last_col = data->map.width - 1;
	i = 0;
	while (i < data->map.width)
	{
		if (data->map.grid[0][i] != '1' || data->map.grid[last_row][i] != '1')
			error_msg("The map must be surrounded by walls (top and bottom).");
		i++;
	}
	i = 0;
	while (i < data->map.height)
	{
		if (data->map.grid[i][0] != '1' || data->map.grid[i][last_col] != '1')
			error_msg("The map must be surrounded by walls (left and right).");
		i++;
	}
}
