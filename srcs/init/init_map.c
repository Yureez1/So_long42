/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:35 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/05 21:04:36 by jbanchon         ###   ########.fr       */
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
	if (data->map.grid && data->map.grid[0])
		data->win_width = (ft_strlen(data->map.grid[0]) - 1) * IMG_SIZE;
	else
		data->win_width = 0; // Valeur par défaut ou gestion d'erreur
}*/
int	init_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->map.player_count = 0;
	data->map.exit_count = 0;
	data->map.collectible_count = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->count_step = 0;
	if (data->map.line_count <= 0)
	{
		// Gestion d'erreur si le nombre de lignes est invalide
		data->win_height = 0;
		data->win_width = 0;
		return 1 ;
	}
	data->win_height = data->map.line_count * IMG_SIZE;
	if (data->map.grid && data->map.grid[0])
	{
		data->win_width = (ft_strlen(data->map.grid[0]) - 1) * IMG_SIZE;
	}
	else
	{
		// Valeur par défaut ou gestion d'erreur
		data->win_width = 0;
	}
	data->img_height = IMG_SIZE;
	data->img_width = IMG_SIZE;
	return (1);
}
