/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:56 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/20 17:51:23 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_parameters(t_data *data);
int	check_map(t_data *data);
int	count_elements_in_map(t_data *data);
void	check_columns(t_data *data);
void	check_rows(t_data *data);

int	check_map(t_data *data)
{
	check_rows(data);
	check_columns(data);
	count_elements_in_map(data);
	map_parameters(data);
	return (SUCCESS);
}

void	check_rows(t_data *data)
{
	int	i;
	int	line_count;

	line_count = data->map.line_count;
	i = 0;
	while (i < line_count)
	{
		if (data->map.grid[i][0] != '1')
			error_msg("Invalid Map. There is a Wall missing on the left side of row %d!\n", data);
		else if (data->map.grid[i][ft_strlen(data->map.grid[i]) - 1] != '1')
			error_msg("Invalid Map. There is a Wall missing on the right side of row %d!\n", data);
		i++;
	}
}

void	check_columns(t_data *data)
{
	int	i;
	int	column_count;
	int line_count;

	line_count = data->map.line_count;
	column_count= ft_strlen(data->map.grid[0]);
	i = 0;
	while (i < column_count)
	{
		if (data->map.grid[i][0] != '1')
			error_msg("Invalid Map. There is a Wall missing on the top side of column %d!\n", data);
		else if (data->map.grid[line_count - 1][i] != '1')
			error_msg("Invalid Map. There is a Wall missing on the bottom side of column %d!\n", data);
		i++;
	}
}

int	count_elements_in_map(t_data *data)
{
	data->y = 0;
	while (data->map.grid[data->y])
	{
		data->x = 0;
		while (data->map.grid[data->y][data->x])
		{
			if (!ft_strchr("CEP01", data->map.grid[data->y][data->x]))
				error_msg("Invalid Map. Not expected map parameter!", data);
			if (data->map.grid[data->y][data->x] == 'P')
				data->map.player_count++;
			else if (data->map.grid[data->y][data->x] == 'E')
				data->map.exit_count++;
			else if (data->map.grid[data->y][data->x] == 'C')
				data->map.collectible_count++;
			data->x++;
		}
		data->y++;
	}
	return (SUCCESS);
}

void	map_parameters(t_data *data)
{
	if (data->map.collectible_count == 0)
		error_msg("Invalid Map. There are no Coins!", data);
	else if (data->map.exit_count == 0)
		error_msg("Invalid Map. There is no Exit!", data);
	else if  (data->map.player_count != 1)
		error_msg ("Invalid Map. Invalid Player quantity!", data);
}
