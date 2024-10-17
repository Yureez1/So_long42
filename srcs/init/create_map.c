/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:38 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/17 12:26:20 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	returned_line(char *filename)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	line = get_next_line(fd);
	if (line == NULL)
		return (free(line), 1);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

void	set_input_map(int row, int fd, t_data *data)
{
	int		column;
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		column = 0;
		data->map.grid[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.grid[row])
		{
			ft_free(data->map.grid);
			close(fd);
			return ;
		}
		while (line[column] != '\0')
		{
			data->map.grid[row][column] = line[column];
			column++;
		}
		data->map.grid[row][column] = '\0';
		free(line);
		row++;
		line = get_next_line(fd);
	}
	data->map.grid[row] = NULL;
}

int	allocate_map_rows(t_data *data)
{
	int	i;

	if (data->map.line_count <= 0)
		return (FAILURE);
	data->map.grid = (char **)malloc((data->map.line_count + 1)
			* sizeof(char *));
	if (data->map.grid == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->map.line_count + 1)
	{
		data->map.grid[i] = NULL;
		i++;
	}
	return (1);
}

int	create_map(char *filename, t_data *data)
{
	int	fd;
	int	row;

	data->map.line_count = returned_line(filename);
	if (data->map.line_count <= 0)
		return (FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !allocate_map_rows(data))
	{
		if (fd >= 0)
			close(fd);
		return (FAILURE);
	}
	row = 0;
	set_input_map(row, fd, data);
	close(fd);
	return (SUCCESS);
}
