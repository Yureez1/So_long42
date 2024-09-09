/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:38 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/06 18:15:53 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../includes/so_long.h"

void	ft_free(char **grid)
{
	size_t	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
	return ;
}

int	returned_line(char *filename)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(filename, O_RDONLY);
	line_count = 0;
	if (fd < 0)
		perror("Error opening file");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	printf("Number of lines in file: %d\n", line_count);
	return(line_count);
}

void	set_input_map(int row, t_data *data)
{
	int		col;
	char	c;

	col = 0;
	while (data->map.grid[row][col] != '\0')
	{
		c = data->map.grid[row][col];
		if (c == '\n')
			break ;
		//printf("Character at [%d][%d]: %c\n", row, col, c);
		if (c == 'P')
			data->map.player_count++;
		else if (c == 'E')
			data->map.exit_count++;
		else if (c == 'C')
			data->map.collectible_count++;
		else if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
			error_msg("Invalid character in map");
		col++;
	}
	if (col < data->map.height)
		data->map.grid[row][col] = '\0';
}

int	allocate_map_rows(t_data *data)
{
	if(data->map.height <= 0)
		return (0);
	data->map.grid = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!data->map.grid)
		return (0);
	return (1);
}

int	create_map(char *filename, t_data *data)
{
	int		fd;
	int		row;
	char	*line;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !allocate_map_rows(data))
		return (0);
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		data->map.grid[row] = ft_strdup(line);
		if (!data->map.grid[row])
		{
			free(line);
			return (0);
		}
		free(line);
		set_input_map(row, data);
		row++;
	}
	data->map.grid[row] = NULL;
	close(fd);
	return (1);
}*/

#include "../includes/so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return;
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
		return (-1);
	line = get_next_line(fd);
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
			return;
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
	if (data->map.line_count <= 0)
		return (0);
	data->map.grid = ft_calloc(data->map.line_count + 1, sizeof(char *));
	return (data->map.grid != NULL);
}

int	create_map(char *filename, t_data *data)
{
	int fd;
	int row;

	data->map.line_count = returned_line(filename);
	if(data->map.line_count <= 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if(fd < 0 || !allocate_map_rows(data))
	{
		if (fd >= 0)
			close(fd);;
		return (0);
	}
	row = 0;
	set_input_map(row, fd, data);
	close(fd);
	return (1);
}
