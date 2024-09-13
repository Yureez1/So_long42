/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/13 18:38:48 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

// Fonction principale du programme
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		create_map(argv[1], &data);
		printf("Create Map OK\n");
		init_map(&data);
		printf("Init map OK\n");
		//check_map(&data);
		printf("Check Map OK\n");
		count_elements_in_map(data.map.grid, &data);
		init_player(&data);
		init_window(&data);
		load_images(&data);
		render(&data);
		images_loop(&data);
		destroy_image(&data);
		free(data.mlx_ptr);
		if (data.map.grid)
			ft_free(data.map.grid);
	}
}
