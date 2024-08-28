/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:29:31 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/28 14:45:00 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "so_long_utils/so_long_utils.h"

//Function to initialise the structure of window
window_t *init_window_struct(void)
{
	window_t *data;
	
	data = malloc(sizeof(window_t));
	if (data == NULL)
		return (NULL);
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	return (data);
}

// Function to initialie connection
int init_mlx_connection(window_t *data)
{
	data->mlx_ptr = mlx_init();
	if(data -> mlx_ptr == NULL)
	{
		free(data);
		return (EXIT_FAILURE);
	}
	return (0);
}
int create_mlx_window(window_t *data, int width, int height, const char *title)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, width, height, (char *)title);
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (EXIT_FAILURE);
	}
	return (0);
}

// Function to initialise the window
int iniatializing_window(void)
{
	window_t *data;
	
	data = init_window_struct();
	if(data == NULL)
		return (EXIT_FAILURE);
	if(init_mlx_connection(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_mlx_window(data, 860, 640, "MY_MAP") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	return (0);
}

int main(void)
{
	return iniatializing_window();
	
}
