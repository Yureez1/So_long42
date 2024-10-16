/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/16 18:49:57 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

// Fonction principale du programme
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !is_ber_file(argv[1]))
	{
		ft_printf(RED"ERROR USAGE: %s <map_file.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		create_map(argv[1], &data);
		init_map(&data);
		check_map(&data);
		init_player(&data);
		ft_duplicate(&data, argv[1]);
		check_image_exist(&data);
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
