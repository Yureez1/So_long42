/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:07:41 by jbanchon          #+#    #+#             */
/*   Updated: 2024/07/21 15:31:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
}			data_t;

void	load_image(data_t *data, const char *file_path)
{
	int	width;
	int	height;

	data ->img = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file_path, &width,
			&height);
}

int	main(void)
{
	data_t	data;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*mlx_win;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480,
				"Hello world")) == NULL)
		return (EXIT_FAILURE);
	load_image(&data, "Documents/wall.xpm");
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}*/

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct data_s
{
    void    *mlx_ptr;
    void    *mlx_win;
    void    *img;  // Utilisation de void* pour img
}           data_t;

void    load_image(data_t *data, const char *file_path)
{
    int width, height;

    printf("Attempting to load image from: %s\n", file_path);
    data->img = mlx_xpm_file_to_image(data->mlx_ptr, (char *)file_path, &width, &height);
    if (data->img == NULL)
    {
        fprintf(stderr, "Failed to load image: %s\n", file_path);
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    data_t data;

    // Initialiser MiniLibX
    if ((data.mlx_ptr = mlx_init()) == NULL)
    {
        fprintf(stderr, "Failed to initialize MiniLibX\n");
        return (EXIT_FAILURE);
    }

    // Créer une nouvelle fenêtre
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
    {
        fprintf(stderr, "Failed to create new window\n");
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Charger l'image avec le chemin absolu
    load_image(&data, "/home/jbanchon/github/Cercle_2/So_long42/game_img/wall.xpm");

    // Afficher l'image dans la fenêtre
    if (mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 150, 150) == -1)
    {
        fprintf(stderr, "Failed to put image to window\n");
        mlx_destroy_window(data.mlx_ptr, data.mlx_win);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Lancer la boucle d'événements
    mlx_loop(data.mlx_ptr);

    // Nettoyage (en théorie, jamais atteint dans une boucle infinie)
    mlx_destroy_window(data.mlx_ptr, data.mlx_win);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);

    return (EXIT_SUCCESS);
}
