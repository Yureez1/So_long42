/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:51 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/20 11:48:03 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (EXIT_SUCCESS);
	}
	else if(keysym == XK_w)
		player_mouv(data, 0 , -1);
	else if (keysym == XK_s)
		player_mouv(data, 0, 1);
	else if (keysym == XK_a)
		player_mouv(data, -1, 0);
	else if (keysym == XK_d)
		player_mouv(data, 1, 0);
	return (SUCCESS);
}

int handle_btnrelease(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (EXIT_SUCCESS);
}

