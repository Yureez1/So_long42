/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/14 12:46:32 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_line(char *str, t_data *data, char **map_copy, int i)
{
	int	j;

	map_copy[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!map_copy[i])
	{
		ft_free_copy(data, map_copy);
		error_msg("Error: MALLOC\n", data);
	}
	j = 0;
	while (str[j] != '\0')
	{
		map_copy[i][j] = str[j];
		j++;
	}
	map_copy[i][j] = '\0';
}

void	ft_copy(t_data *data, char *filename, char **map_copy)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_msg("Error: Cannot open file\n", data);
		return ;
	}
	i = 0;
	while (i < data->map.line_count)
	{
		str = get_next_line(fd);
		if (!str)
		{
			map_copy[i] = NULL;
			break ;
		}
		copy_line(str, data, map_copy, i);
		free(str);
		i++;
	}
	if (close(fd) < 0)
		error_msg("Error closing file", data);
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

/*void	ft_duplicate(t_data *data, char *filename)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = (char **)malloc(sizeof(char *) * (data->map.line_count + 1));
	if (!map_copy)
		error_msg("Error: MALLOC\n", data);
	ft_copy(data, filename, map_copy);
	init_player(data);
	flood_fill(data, map_copy, (t_vector){data->player_pos.x,
		data->player_pos.y});
	i = 0;
	while (i < data->map.line_count)
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
				error_msg("Flood Fill! Element not reachable!\n", data);
			j++;
		}
		i++;
	}
	ft_free_copy(data, map_copy);
}*/

void	flood_fill(t_data *data, char **map_copy, t_vector pos, char target)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x < 0 || y < 0 || y >= data->map.line_count
		|| x >= (int)ft_strlen(data->map.grid[0]))
		error_msg("Out of borders\n", data);
	if (map_copy[y][x] == 'E' && target == 'C')
		return;
	if (map_copy[y][x] == target)
	{
		if (target == 'E')
			data->map.can_exit++;
		else if (target == 'C')
			data->map.collectibles_reached++;
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	flood_fill(data, map_copy, (t_vector){x, y + 1}, target);
	flood_fill(data, map_copy, (t_vector){x, y - 1}, target);
	flood_fill(data, map_copy, (t_vector){x + 1, y}, target);
	flood_fill(data, map_copy, (t_vector){x - 1, y}, target);
}


void	check_for_exit(t_data *data, char *filename)
{
	char	**map_copy;

	map_copy = (char **)malloc(sizeof(char *) * (data->map.line_count + 1));
	if (!map_copy)
		error_msg("Error: MALLOC\n", data);
	ft_copy(data, filename, map_copy);
	init_player(data);
	data->map.exit_reached = 0;
	flood_fill(data, map_copy, (t_vector){data->player_pos.x,
		data->player_pos.y}, 'E');
	if (data->map.can_exit > 0)
		ft_printf("Exit is reacheable\n");
	else
		error_msg("Error : Exit is not reacheable\n", data);
	ft_free_copy(data, map_copy);
}

void	check_for_collectibles(t_data *data, char *filename)
{
		char	**map_copy;

	map_copy = (char **)malloc(sizeof(char *) * (data->map.line_count + 1));
	if (!map_copy)
		error_msg("Error: MALLOC\n", data);
	ft_copy(data, filename, map_copy);
	init_player(data);
	data->map.collectibles_reached = 0;
	flood_fill(data, map_copy, (t_vector){data->player_pos.x,
		data->player_pos.y}, 'C');
	if (data->map.collectibles_reached == data->map.collectible_count)
		ft_printf("Collectibles are reacheable\n");
	else
		error_msg("Collectibles are not reacheable\n", data);
	ft_free_copy(data, map_copy);
}

void	ft_duplicate(t_data *data, char *filename)
{
	check_for_collectibles(data, filename);
	check_for_exit(data, filename);
}
