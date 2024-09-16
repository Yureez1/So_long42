/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/16 12:07:39 by jbanchon         ###   ########.fr       */
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
		check_map(&data);
		printf("Check Map OK\n");
		init_player(&data);
		printf("Init player OK\n");
		init_window(&data);
		printf("Init window OK\n");
		load_images(&data);
		printf("Load images OK\n");
		render(&data);
		printf("Render OK\n");
		images_loop(&data);
		printf("Images loop OK\n");
		destroy_image(&data);
		printf("Destroy image OK\n");
		free(data.mlx_ptr);
		if (data.map.grid)
			ft_free(data.map.grid);
	}
}
