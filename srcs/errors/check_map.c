/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:56 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/16 11:55:23 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	check_top_bot(int row, char **grid)
{
	int	i;

	i = 0;
	while (grid[row][i] && grid[row][i] != '\n')
	{
		if (grid[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_edges(int line_count, char **grid)
{
	int	i;

	i = 0;
	if (check_top_bot(0, grid) == FAILURE || check_top_bot(line_count - 1,
			grid) == FAILURE)
		return (FAILURE);
	while (i < line_count - 1)
	{
		if (grid[i][0] != '1' || grid[i][ft_strlen(grid[i]) - 2] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(char **grid, int line_count)
{
	int		i;
	size_t	line_len;

	i = 0;
	line_len = ft_strlen(grid[0]) - 1;
	while (i < line_count)
	{
		if (ft_strlen(grid[i]) - 1 != line_len)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int	line_count;

	line_count = 0;
	while (data->map.grid[line_count])
		line_count++;
	if (count_elements_in_map(data->map.grid, data) == FAILURE)
	return (FAILURE);
	if (data->map.player_count != 1)
		return (FAILURE);
	if (check_rectangle(data->map.grid, line_count) == FAILURE)
		return (FAILURE);
	if (check_edges(line_count, data->map.grid) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
