/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 19:34:06 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_data data;
	
	init_map(&data);
	if (argc == 2)
	{
		if (!create_map(argv[1], &data))
		{
			error_msg("Failed to create map");
			return (EXIT_FAILURE);
		}
		init_window(&data);
		load_images(&data);
		render_map(&data);
		mlx_loop(data.mlx_ptr);
		ft_free(data.map.grid);
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (EXIT_SUCCESS);
	}
	else
	{
		error_msg("Usage: ./so_long map_file");
		return (EXIT_FAILURE);
	}
}
