/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/04 13:59:11 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_copy(t_data *data, char *filename, char **map_copy)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < data->map.line_count)
	{
		str = get_next_line(fd);
		if (!str)
			return ;
		map_copy[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!map_copy[i])
			error_msg("Malloc!\n", data);
		j = 0;
		while (str[j])
		{
			map_copy[i][j] = str[j];
			j++;
		}
		free(str);
		i++;
	}
	map_copy[i] = NULL;
}

void	ft_free_copy(t_data *data, char **map_copy)
{
	int	i;

	i = 0;
	while (i < data->map.line_count)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	ft_duplicate(t_data *data, char *filename)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = (char **)malloc(sizeof(char *) * (data->map.line_count + 1));
	if (!map_copy)
		error_msg("Copied Map!n", data);
	ft_copy(data, filename, map_copy);
	init_player(data);
	flood_fill(data, map_copy, (t_vector){data->player_x, data->player_pos.y});
	i = 0;
	while (i < data->map.line_count)
	{
		j = 0;
		while (map_copy[i][j])
		{
			printf("%c", map_copy[i][j]);
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
			{
				printf("Unreachable element '%c' found at [%d, %d]\n",
					map_copy[i][j], i, j);
				error_msg("Flood Fill! Element not reachable!\n", data);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	ft_free_copy(data, map_copy);
}

void	flood_fill(t_data *data, char **map_copy, t_vector pos)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	printf("Flood Fill called with x = %d, y = %d\n", x, y);
	if (x < 0 || y < 0 || y >= data->map.line_count
		|| x >= (int)ft_strlen(data->map.grid[0]))
	{
		printf("Map height %d\n", data->map.line_count);
		printf("Map width %d\n", (int)ft_strlen(data->map.grid[0]));
		error_msg("Out of borders\n", data);
		return ;
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	flood_fill(data, map_copy, (t_vector){x, y + 1});
	flood_fill(data, map_copy, (t_vector){x, y - 1});
	flood_fill(data, map_copy, (t_vector){x + 1, y});
	flood_fill(data, map_copy, (t_vector){x - 1, y});
}
