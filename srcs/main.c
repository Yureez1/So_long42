/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:24 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/05 21:00:45 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void clean_up(t_data *data)
{
    if (data->map.grid)
        ft_free(data->map.grid);
    // Ajoutez ici le nettoyage des autres ressources si nécessaire
}

int main(int argc, char *argv[])
{
    t_data data;

    // Initialisation des données
    memset(&data, 0, sizeof(t_data)); // Assurez-vous que `data` est initialisé correctement

    if (argc == 2)
    {
        if (!create_map(argv[1], &data))
        {
            error_msg("Failed to create map");
            clean_up(&data);
            return (EXIT_FAILURE);
        }
        init_map(&data);
        
        if (data.map.player_count < 1 || data.map.exit_count != 1 || data.map.collectible_count < 1)
        {
            error_msg("Map validation failed");
            clean_up(&data);
            return (EXIT_FAILURE);
        }

        if (!init_player(&data) || !init_window(&data) || !load_images(&data))
        {
            error_msg("Initialization failed");
            clean_up(&data);
            return (EXIT_FAILURE);
        }

        render_map(&data);
        images_loop(&data);
        destroy_image(&data);
        clean_up(&data);
        return (EXIT_SUCCESS);
    }
    else
    {
        error_msg("Usage: ./so_long map_file");
        return (EXIT_FAILURE);
    }
}

