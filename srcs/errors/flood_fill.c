/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/26 11:16:58 by jbanchon         ###   ########.fr       */
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
	printf("Player Position: (%d, %d)\n", data->player_pos.x, data->player_pos.y);
	printf("Player is at: %c\n", data->map.grid[data->player_pos.y][data->player_pos.x]);
	if (is_out(pos.x, pos.y, data->map.width, data->map.height)
		|| map_clone[pos.y][pos.x] == '1' || map_clone[pos.y][pos.x] == 'V')
		return (0);
	if (to_find(str, map_clone[pos.y][pos.x]))
	{
		elements_count = 1;
		printf("Found element: %c at (%d, %d)\n", map_clone[pos.y][pos.x], pos.x, pos.y);
	}
	printf("Flood fill at (%d, %d) - current cell: %c\n", pos.x, pos.y, map_clone[pos.y][pos.x]);
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
			{
				total_count++;
				printf("Counting element: %c at (%d, %d)\n", map_clone[y][x], x, y);
			}
			x++;
		}
		y++;
	}
	return (total_count);
}

/*void	check_map_playability(t_data *data)
{
	char	**map_clone;
	int		collected;
	int		expected_elements;

	map_clone = copy_map(data->map.grid, data->map.line_count);
	if (!map_clone)
		end_game("An error occurred saving the map", data, map_error, NULL);
	expected_elements = total_elements(data, map_clone, "CPE");
	printf("Expected elements (C, E, P): %d\n", expected_elements);
	collected = flood_fill(data, map_clone, data->player_pos, "CP0");
	printf("Expected: %d, Collected: %d\n", expected_elements, collected);
	if (collected == expected_elements)
	{
		map_clone = copy_map(data->map.grid, data->map.line_count);
		if (!map_clone)
			end_game("Could not save the map.", data, map_error, NULL);
		collected = flood_fill(data, map_clone, data->player_pos, "ECP0");
		ft_free(map_clone);
	}
	if (collected != expected_elements)
		end_game("Unplayable map.", data, map_error, NULL);
	return ;
}*/

void check_map_playability(t_data *data)
{
    char **map_clone;
    int collected;
    int expected_elements;

    map_clone = copy_map(data->map.grid, data->map.line_count);
    if (!map_clone)
        end_game("An error occurred saving the map", data, map_error, NULL);

    expected_elements = total_elements(data, map_clone, "CPE");

    // Check if player position is valid before using it
    if (data->player_pos.x < 0 || data->player_pos.x >= data->map.width ||
        data->player_pos.y < 0 || data->player_pos.y >= data->map.height)
    {
        fprintf(stderr, "Error: Invalid player position (%d, %d).\n",
                data->player_pos.x, data->player_pos.y);
        end_game("Invalid player position.", data, map_error, NULL);
    }

    printf("Player is at: %c\n", data->map.grid[data->player_pos.y][data->player_pos.x]);

    collected = flood_fill(data, map_clone, data->player_pos, "CP0");
    printf("Expected: %d, Collected: %d\n", expected_elements, collected);
    if (collected == expected_elements)
    {
        map_clone = copy_map(data->map.grid, data->map.line_count);
        if (!map_clone)
            end_game("Could not save the map.", data, map_error, NULL);
        collected = flood_fill(data, map_clone, data->player_pos, "ECP0");
        ft_free(map_clone);
    }
    if (collected != expected_elements)
        end_game("Unplayable map.", data, map_error, NULL);
}



char	**copy_map(char **grid, int line_count)
{
	char	**map_clone;
	int		i;

	i = 0;
	map_clone = malloc(sizeof(char *) * (line_count + 1));
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
				ft_free(map_clone);
			}
			ft_free(map_clone);
			return (NULL);
		}
		i++;
	}
	map_clone[line_count] = NULL;
	return (map_clone);
}
