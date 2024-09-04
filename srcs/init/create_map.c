/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:38 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 17:50:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	returned_line(char *filename)
{
	int fd;
	int line_count;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);
	return(line_count);
}

void set_input_map(int row, t_data *data)
{
	int col;
	char c;
	int i;
	
	col = 0;
	while(data->map.grid[row][i] != '\0')
	{
		c = data->map.grid[row][i];
		if (c == 'P')
			data->map.player_count++;
		else if (c == 'E')
			data->map.exit_count++;
		else if (c != '0' && c != '1' && c != 'C')
			error_msg("Invalid character in map");
		data->map.grid[row][col++] = c;
		i++;
	}
	data->map.grid[row][col] = '\0';
}

int allocate_map_rows(t_data *data)
{
	data->map.grid = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.grid)
		return (0);
	return (1);
}

int create_map(char *filename, t_data *data)
{
	int fd;
	int row;

	fd = open(filename, O_RDONLY);
	if(fd < 0 || !allocate_map_rows(data))
		return (0);
	row = 0;
	while((data->map.grid[row] = get_next_line(fd)) != NULL)
	{
		data->map.grid[row] = malloc(sizeof(char) * (data->win_width + 1));
		if(!data->map.grid[row])
			return(0);
		set_input_map(row, data);
		row++;
	}
	data->map.grid[row] = NULL;
	close(fd);
	return (1);
}
