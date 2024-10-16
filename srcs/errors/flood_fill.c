/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/16 19:02:57 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_data *data, char **map_copy, t_vector pos, char target)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x < 0 || y < 0 || y >= data->map.line_count
		|| x >= (int)ft_strlen(data->map.grid[0]))
		error_msg("Out of borders\n", data);
	if (map_copy[y][x] == 'E' && target == 'C')
		return ;
	if (map_copy[y][x] == target)
	{
		if (target == 'E')
			data->map.can_exit++;
		else if (target == 'C')
			data->map.collectibles_reached++;
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	flood_fill(data, map_copy, (t_vector){x, y + 1}, target);
	flood_fill(data, map_copy, (t_vector){x, y - 1}, target);
	flood_fill(data, map_copy, (t_vector){x + 1, y}, target);
	flood_fill(data, map_copy, (t_vector){x - 1, y}, target);
}

void	check_for_exit(t_data *data, char *filename)
{
	char	**map_copy;

	map_copy = (char **)malloc((data->map.line_count + 1) * sizeof(char *));
	if (!map_copy)
	{
		error_msg("Error: MALLOC\n", data);
		return ;
	}
	ft_copy(data, filename, map_copy);
	init_player(data);
	data->map.can_exit = 0;
	flood_fill(data, map_copy, (t_vector){data->player_pos.x,
		data->player_pos.y}, 'E');
	if (data->map.can_exit > 0)
		ft_printf("Exit is reacheable\n");
	else
	{
		ft_free_copy(data, map_copy);
		error_msg("Error : Exit is not reacheable\n", data);
	}
	ft_free_copy(data, map_copy);
}

void	check_for_collectibles(t_data *data, char *filename)
{
	char	**map_copy;

	map_copy = (char **)malloc((data->map.line_count + 1) * sizeof(char *));
	if (!map_copy)
	{
		error_msg("Error: MALLOC\n", data);
		return ;
	}
	ft_copy(data, filename, map_copy);
	init_player(data);
	data->map.collectibles_reached = 0;
	flood_fill(data, map_copy, (t_vector){data->player_pos.x,
		data->player_pos.y}, 'C');
	if (data->map.collectibles_reached == data->map.collectible_count)
		ft_printf("Collectibles are reacheable\n");
	else
	{
		ft_free_copy(data, map_copy);
		error_msg("Collectibles are not reacheable\n", data);
	}
	ft_free_copy(data, map_copy);
}

void	ft_duplicate(t_data *data, char *filename)
{
	check_for_collectibles(data, filename);
	check_for_exit(data, filename);
}
