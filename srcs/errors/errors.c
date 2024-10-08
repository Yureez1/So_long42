/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:54 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/08 12:03:04 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(char *message, t_data *data)
{
	if (data->map.grid)
		ft_free(data->map.grid);
	ft_printf(RED"ERROR\n"GREY"%s\n"RESET, message);
	exit(1);
}
