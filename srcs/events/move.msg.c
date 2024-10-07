/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:48 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/07 16:04:19 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_count_step(t_data *data, char direction)
{
	if (ft_strchr("wasd", direction))
	{
		data->count_step++;
		ft_printf("Steps: %d\n", data->count_step);
	}
	return (0);
}
