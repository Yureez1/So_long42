/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:28:23 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/29 22:41:00 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>    // Pour XK_* codes
#include <X11/Xlib.h> // Pour XEvent
#include <fcntl.h>    // Pour open
#include <stdio.h>    // Pour perror et fprintf
#include <stdlib.h>   // Pour malloc et free
#include <unistd.h>   // Pour close

// Prototypes des fonctions
char	**read_map(const char *filename, data_t *data,
			data_player_move_t *player_mouv);
void	put_img(data_t *data, void *img, int x, int y);
int		img_textures(data_t *data);
int		load_textures_errors(data_t *data);
void	free_textures(data_t *data);
void	key_assignment(int keycode, data_player_move_t *player_mouv);
void	update_player_position(data_player_move_t *player_mouv,
			pos_t *player_pos);
void	handle_key_press(XKeyEvent *event, data_player_move_t *player_mouv,
			pos_t *player_pos);
int		update_window(void *param);

char	**read_map(const char *filename, data_t *data,
		data_player_move_t *player_mouv)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	printf("File opened successfully.\n");
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == '1')
				put_img(data, data->textures.game_img_wall, x, y);
			else if (line[x] == '0')
				put_img(data, data->textures.game_img_floor, x, y);
			else if (line[x] == 'C')
				put_img(data, data->textures.game_img_collectible, x, y);
			else if (line[x] == 'P')
			{
				put_img(data, data->textures.game_img_character, x, y);
				player_mouv->x = x;
				player_mouv->y = y;
			}
			else if (line[x] == 'E')
				put_img(data, data->textures.game_img_exit, x, y);
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	return (NULL);
}

void	put_img(data_t *data, void *img, int x, int y)
{
	int	tile_size;

	tile_size = 16;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x * tile_size, y
		* tile_size);
}

void	print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
}

int	img_textures(data_t *data)
{
	int	width;
	int	height;

	data->textures.game_img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"game_img/wall.xpm", &width, &height);
	if (!data->textures.game_img_wall)
		print_error("Error loading wall image");
	data->textures.game_img_character = mlx_xpm_file_to_image(data->mlx_ptr,
			"game_img/character.xpm", &width, &height);
	if (!data->textures.game_img_character)
		print_error("Error loading character image");
	data->textures.game_img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"game_img/door.xpm", &width, &height);
	if (!data->textures.game_img_exit)
		print_error("Error loading exit image");
	data->textures.game_img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"game_img/floor.xpm", &width, &height);
	if (!data->textures.game_img_floor)
		print_error("Error loading floor image");
	data->textures.game_img_collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"game_img/key.xpm", &width, &height);
	if (!data->textures.game_img_collectible)
		print_error("Error loading collectible image");
	return (EXIT_SUCCESS);
}

int	load_textures_errors(data_t *data)
{
	if (!data->textures.game_img_wall || !data->textures.game_img_floor
		|| !data->textures.game_img_character
		|| !data->textures.game_img_collectible
		|| !data->textures.game_img_exit)
		// Removed `game_img_enemy` check
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	free_textures(data_t *data)
{
	if (data->textures.game_img_wall)
		mlx_destroy_image(data->mlx_ptr, data->textures.game_img_wall);
	if (data->textures.game_img_floor)
		mlx_destroy_image(data->mlx_ptr, data->textures.game_img_floor);
	if (data->textures.game_img_character)
		mlx_destroy_image(data->mlx_ptr, data->textures.game_img_character);
	if (data->textures.game_img_collectible)
		mlx_destroy_image(data->mlx_ptr, data->textures.game_img_collectible);
	if (data->textures.game_img_exit)
		mlx_destroy_image(data->mlx_ptr, data->textures.game_img_exit);
}

int	handle_keypress(int keycode, data_player_move_t *player_mouv)
{
	if (keycode == XK_Escape)
		exit(EXIT_SUCCESS);
	else if (keycode == XK_Up)
		player_mouv->y -= 1;
	else if (keycode == XK_Down)
		player_mouv->y += 1;
	else if (keycode == XK_Left)
		player_mouv->x -= 1;
	else if (keycode == XK_Right)
		player_mouv->x += 1;
	return (0);
}
int	update_window(void *param)
{
	all_data_t	*all_data;

	all_data = (all_data_t *)param;
	mlx_clear_window(all_data->data->mlx_ptr, all_data->data->mlx_win);
	read_map("maps/map1.ber", all_data->data, all_data->player_mouv);
	put_img(all_data->data, all_data->data->textures.game_img_character,
		all_data->player_mouv->x, all_data->player_mouv->y);
	return (0);
}

int	main(void)
{
	data_t				*data;
	data_player_move_t	player_mouv;
	all_data_t			all_data;

	// Allocation et initialisation de data
	data = malloc(sizeof(data_t));
	if (data == NULL)
	{
		perror("Error allocating memory for data");
		return (EXIT_FAILURE);
	}
	// Initialisation de mlx et création de la fenêtre
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		perror("Error initializing mlx");
		free(data);
		return (EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "My_Map");
	if (data->mlx_win == NULL)
	{
		perror("Error creating window");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (EXIT_FAILURE);
	}
	// Chargement des textures
	if (img_textures(data) == EXIT_FAILURE)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (EXIT_FAILURE);
	}
	// Initialiser la position du personnage
	player_mouv.x = -1;
	player_mouv.y = -1;
	// Lire la carte et trouver la position de départ du joueur
	if (read_map("maps/map1.ber", data, &player_mouv) == NULL)
	{
		perror("Error reading map");
		free_textures(data);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (EXIT_FAILURE);
	}
	if (player_mouv.x == -1 || player_mouv.y == -1)
	{
		perror("Error: Player start position not found in map");
		free_textures(data);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (EXIT_FAILURE);
	}
	// Préparer la structure all_data
	all_data.data = data;
	all_data.player_mouv = &player_mouv;
	// Configurer les événements
	mlx_key_hook(data->mlx_win, handle_keypress, &player_mouv);
	mlx_loop_hook(data->mlx_ptr, update_window, &all_data);
	mlx_loop(data->mlx_ptr);
	// Libérer les ressources
	free_textures(data);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	return (EXIT_SUCCESS);
}
