/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:56 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/24 12:27:14 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*void	map_parameters(t_data *data);
int		check_map(t_data *data);
int		count_elements_in_map(t_data *data);
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
	int	column_count;
	int	line_count;

	line_count = data->map.line_count;
	column_count = ft_strlen(data->map.grid[0]);
	i = 0;
	while (i < line_count)
	{
		if (data->map.grid[i][0] != '1')
			printf("Invalid Map. There is a Wall missing on the left side of row
				%d!\n", i);
		else if (data->map.grid[i][column_count - 1] != '1')
			printf("Invalid Map. There is a Wall missing on the right side of row
				%d!\n", i);
		i++;
	}
}

void	check_columns(t_data *data)
{
	int	i;
	int	column_count;
	int	line_count;

	line_count = data->map.line_count;
	column_count= ft_strlen(data->map.grid[0]);
	i = 0;
	while (i < column_count)
	{
		if (data->map.grid[0][i] != '1')
			printf("Invalid Map. There is a Wall missing on the top side of column
				%d!\n", i);
		else if (data->map.grid[line_count - 1][i] != '1')
			printf("Invalid Map. There is a Wall missing on the bottom side of column
				%d!\n", i);
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
}*/
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
	if (!data->map.player_count || !data->map.exit_count
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
	while (data->map.grid[i])
	{
		while (j < ft_strlen(data->map.grid[i]) - 1)
		{
			if (ft_strchr("01CEP", data->map.grid[i][j]) == NULL)
				error_msg(ERRORCHR, data);
			j++;
		}
		j = 0;
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
}
