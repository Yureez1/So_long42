/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:56 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/14 16:12:24 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_chars(t_data *data)
{
	data->y = 0;
	while (data->map.grid[data->y])
	{
		while (data->map.grid[data->y][data->x])
		{
			if (data->map.grid[data->y][data->x] == 'P')
				data->map.player_count++;
			else if (data->map.grid[data->y][data->x] == 'E')
				data->map.exit_count++;
			else if (data->map.grid[data->y][data->x] == 'C')
				data->map.collectible_count++;
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	if (data->map.player_count != 1 || data->map.exit_count != 1
		|| !data->map.collectible_count)
		return (FAILURE);
	else
		return (SUCCESS);
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

	i = 1;
	if (check_top_bot(0, grid) == FAILURE || check_top_bot(line_count,
			grid) == FAILURE)
		return (FAILURE);
	while (i < line_count)
	{
		if (grid[i][0] != '1' || grid[i][ft_strlen(grid[0]) - 2] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.grid[i]) - 1;
	while (data->map.grid[i])
	{
		while (data->map.grid[i][j] && data->map.grid[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (FAILURE);
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	for (int k = 0; data->map.grid[k]; k++)
		printf("Row %d: %s\n", k, data->map.grid[k]);
	while (data->map.grid[i])
	{
		while (j < ft_strlen(data->map.grid[i]) - 1)
		{
			if (ft_strchr("01CEP", data->map.grid[i][j]) == NULL)
				error_msg("Cant find 01CEP", data);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_chars(data) == FAILURE)
		error_msg("Map need to have PEC", data);
	if (data->map.player_count > 1)
		error_msg("Map has to have 1 player", data);
	if (check_rectangle(data) == FAILURE)
		error_msg("Map has to be a rectangle", data);
	if (check_edges(data->map.line_count - 1, data->map.grid) == FAILURE)
		error_msg("Map has to be surrounded by walls", data);
	return (SUCCESS);
}

/*int	check_map(t_data *data)
{
	int		i;
	size_t	j;
	size_t	len;

	if (data == NULL || data->map.grid == NULL) // Check for NULL pointers
		return (FAILURE);
	i = 0;
	while (data->map.grid[i])
	{
		len = ft_strlen(data->map.grid[i]);
		while (j < len)
		{
			if (ft_strchr("01CEP", data->map.grid[i][j]) == NULL)
				error_msg(ERRORCHR, data);
			j++;
		}
		i++;
	}
	if (check_chars(data) == FAILURE)
		error_msg(ERRORCHR, data);
	if (data->map.player_count > 1)
		error_msg(ERRORCHR, data);
	if (check_rectangle(data) == FAILURE)
		error_msg(ERRORCHR, data);
	if (check_edges(data->map.line_count - 1, data->map.grid) == FAILURE)
		error_msg(ERRORCHR, data);
	return (SUCCESS);
}*/

