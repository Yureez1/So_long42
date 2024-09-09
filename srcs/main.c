/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/09 18:06:41 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	clean_up(t_data *data)
{
	if (data->map.grid)
		ft_free(data->map.grid);
	// Ajoutez ici le nettoyage des autres ressources si nécessaire
}

#include <stdio.h>
#include <stdlib.h>

// Assuming these headers are included somewhere
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	// Check for correct number of arguments
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	// Initialize the map data
	if (create_map(argv[1], &data) != 0)
	{
		fprintf(stderr, "Error creating map from file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	if (init_map(&data) != 0)
	{
		fprintf(stderr, "Error initializing map\n");
		return (EXIT_FAILURE);
	}
	if (count_elements_in_map(data->map.grid, &data) != 0)
	{
		fprintf(stderr, "Error counting elements in map\n");
		return (EXIT_FAILURE);
	}
	// Uncomment check_map if you need to validate the map
	// if (check_map(&data) != 0) {
	//     fprintf(stderr, "Map validation failed\n");
	//     return (EXIT_FAILURE);
	// }
	if (init_player(&data) != 0)
	{
		fprintf(stderr, "Error initializing player\n");
		return (EXIT_FAILURE);
	}
	if (init_window(&data) != 0)
	{
		fprintf(stderr, "Error initializing window\n");
		return (EXIT_FAILURE);
	}
	if (load_images(&data) != 0)
	{
		fprintf(stderr, "Error loading images\n");
		return (EXIT_FAILURE);
	}
	if (render_map(&data) != 0)
	{
		fprintf(stderr, "Error rendering map\n");
		return (EXIT_FAILURE);
	}
	images_loop(&data);
	destroy_image(&data);
	// Free MLX resources
	if (data.mlx_ptr)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	return (EXIT_SUCCESS);
}
