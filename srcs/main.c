/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/10 17:02:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.grid[i] != NULL)
	{
		printf("%s", data->map.grid[i]);
		i++;
	}
}

// Fonction principale du programme
int	main(int argc, char **argv)
{
	t_data	data;

	// Vérifier le nombre d'arguments
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	// Initialiser la carte
	if (create_map(argv[1], &data) != 1)
	{
		fprintf(stderr, "Error creating map from file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	print_map(&data);
	init_map(&data);
	// Vérifier la structure de la carte
	if (!data.map.grid || data.map.height <= 0 || data.map.width <= 0)
	{
		fprintf(stderr, "Error: Invalid map structure\n");
		ft_free(data.map.grid); // Libérer la mémoire allouée
		return (EXIT_FAILURE);
	}
	// Compter les éléments dans la carte
	count_elements_in_map(data.map.grid, &data);
	// Initialiser le joueur
	if (init_player(&data) != 0)
	{
		fprintf(stderr, "Error initializing player\n");
		ft_free(data.map.grid); // Libérer la mémoire allouée
		return (EXIT_FAILURE);
	}
	// Charger les images
	if (load_images(&data) != 0)
	{
		fprintf(stderr, "Error loading images\n");
		ft_free(data.map.grid); // Libérer la mémoire allouée
		return (EXIT_FAILURE);
	}
	// Démarrer le rendu graphique
	core_render(&data);
	// Libérer les ressources après la fin du programme
	destroy_image(&data);
	ft_free(data.map.grid); // Libérer la mémoire allouée
	return (EXIT_SUCCESS);
}
