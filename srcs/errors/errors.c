/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:54 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/26 10:46:19 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(char *message, t_data *data)
{
	if (data->map.grid)
		ft_free(data->map.grid);
	printf(RED"ERROR\n"GREY"%s\n"RESET, message);
	exit(1);
}

void	end_game(char *msg, t_data *data, enum e_state state, char *free_me)
{
	if (state == event_end)
	{
		ft_printf("%s\n", msg);
		destroy_image(data);
		exit(0);
	}
	else if (state == file_error)
	{
		ft_printf("Error\n File_ERROR : %s\n", msg);
		if (free_me != NULL)
			free(free_me);
		exit(1);
	}
	else if (state == map_error)
	{
		ft_printf("Error\n Map Error : %s\n", msg);
		ft_free(data->map.grid);
		if (free_me != NULL)
			free(free_me);
		exit (2);
	}
	ft_printf("Error\n%s\n", msg);
	destroy_image(data);
	exit (3);
}

