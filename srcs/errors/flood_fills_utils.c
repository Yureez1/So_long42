/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fills_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:02:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/16 19:03:13 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_line(char *str, t_data *data, char **map_copy, int i)
{
	int	j;

	map_copy[i] = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!map_copy[i])
	{
		ft_free_copy(data, map_copy);
		error_msg("Error: MALLOC\n", data);
		return ;
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
			ft_free_copy(data, map_copy);
			close(fd);
			return ;
		}
		copy_line(str, data, map_copy, i);
		free(str);
		i++;
	}
	close(fd);
}

void	ft_free_copy(t_data *data, char **map_copy)
{
	int	i;

	i = 0;
	if (map_copy)
	{
		while (i < data->map.line_count)
		{
			if (map_copy[i])
			{
				free(map_copy[i]);
				map_copy[i] = NULL;
			}
			i++;
		}
		free(map_copy);
		map_copy = NULL;
	}
}
