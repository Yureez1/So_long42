/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/24 16:52:27 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_out(int x, int y, int size_x, int size_y)
{
	return (x < 0 || x >= size_x || y < 0 || y >= size_y);
}

int	to_find(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	flood_fill(t_data *data, char **map_clone, t_vector pos, char *str)
{
	int	elements_count;

	elements_count = 0;
	if (is_out(pos.x, pos.y, data->map.width, data->map.height)
		|| map_clone[pos.y][pos.x] == '1' || map_clone[pos.y][pos.x] == 'V')
		return (0);
	if (to_find(str, map_clone[pos.y][pos.x]))
		elements_count = 1;
	map_clone[pos.y][pos.x] = 'V';
	elements_count += flood_fill(data, map_clone, (t_vector){pos.x - 1, pos.y},
			str);
	elements_count += flood_fill(data, map_clone, (t_vector){pos.x + 1, pos.y},
			str);
	elements_count += flood_fill(data, map_clone, (t_vector){pos.x, pos.y - 1},
			str);
	elements_count += flood_fill(data, map_clone, (t_vector){pos.x, pos.y + 1},
			str);
	return (elements_count);
}

int	total_elements(t_data *data, char **map_clone, char *elements)
{
	int	total_count;
	int	x;
	int	y;

	total_count = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (to_find(elements, map_clone[y][x]))
				total_count++;
			x++;
		}
		y++;
	}
	return (total_count);
}

void	check_map_playability(t_data *data)
{
	char	**map_clone;
	int		collected;
	int		expected_elements;

	map_clone = copy_map(data->map.grid, data->map.line_count);
	if (!map_clone)
		return ;
	expected_elements = total_elements(data, map_clone, "CPE");
	collected = flood_fill(data, map_clone, data->player_pos, "CPE");
	if (collected == expected_elements)
		printf("Map is playable\n");
	else
		printf("Map is not playable. Collected: %d, Expected: %d\n", collected,
			expected_elements);
	free(map_clone);
}

char	**copy_map(char **grid, int line_count)
{
	char	**map_clone;
	int		i;

	i = 0;
	map_clone = malloc(sizeof(char *) * line_count);
	if (!map_clone)
		return (NULL);
	while (i < line_count)
	{
		map_clone[i] = ft_strdup(grid[i]);
		if (!map_clone[i])
		{
			while (i > 0)
			{
				i--;
				free(map_clone[i]);
			}
			free(map_clone);
			return (NULL);
		}
		i++;
	}
	return (map_clone);
}
