/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:35 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/16 18:59:04 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_map(t_data *data)
{
	if (!data->map.grid || !data->map.grid[0])
	{
		error_msg("Map grid is empty or invalid", data);
		exit(EXIT_FAILURE);
	}
	data->x = 0;
	data->y = 0;
	data->map.player_count = 0;
	data->map.exit_count = 0;
	data->map.collectible_count = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->count_step = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = ft_strlen(data->map.grid[0]) * IMG_SIZE;
	data->sprites.height = IMG_SIZE;
	data->sprites.width = IMG_SIZE;
	return (SUCCESS);
}
