/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:38 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/03 16:49:38 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	line_count = 0;
	while (fd < 0)
		return (-1);
	while((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);
	return(line_count);
}

void set_input_map(int row, int i, t_data *data)
{
	int col;
	char c;
	
	col = 0;
	while(data->map_input[i])
	{
		c = data->map_input[i];
		if (c == 'P')
			data->player_count++;
		else if (c == 'E')
			data->exit_count++;
		else if (c != '0' && c != '1' && c != 'C')
			error_msg("Invalid character in map");
		data->map[row][col++] = c;
		i++;
	}
	data->map[row][col] = '\0';
}

int allocate_map_rows(t_data *data)
{
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
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
	while((data->map_input = get_next_line(fd)) != NULL)
	{
		data->map[row] = malloc(sizeof(char) * (data->map_width + 1));
		if(!data->map[row])
			return(0);
		set_input_map(row++, 0, data);
		free(data->map_input);
	}
	data->map[row] = NULL;
	close(fd);
	return (1);
}
