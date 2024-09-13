/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:35 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/13 12:36:51 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*void	init_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->map.player_count = 0;
	data->map.exit_count = 0;
	data->map.collectible_count = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->count_step = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.grid[0]) - 1) * IMG_SIZE;
	data->img_height = IMG_SIZE;
	data->img_width = IMG_SIZE;
}*/

void	init_map(t_data *data)
{
	if (!data->map.grid || !data->map.grid[0])
	{
		error_msg("Map grid is empty or invalid");
		exit(EXIT_FAILURE);
	}

	data->i = 0;
	data->j = 0;
	data->map.player_count = 0;
	data->map.exit_count = 0;
	data->map.collectible_count = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->count_step = 0;

	// Calculer les dimensions de la fenêtre en fonction de la carte
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = ft_strlen(data->map.grid[0]) * IMG_SIZE;

	data->sprites.height = IMG_SIZE;
	data->sprites.width = IMG_SIZE;
}

