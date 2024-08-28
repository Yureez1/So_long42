/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_assignment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:59:42 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/28 14:14:56 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include "so_long_utils/so_long_utils.h"

void	key_assignment(int keycode, data_player_mouv_t *player_mouv)
{
	if(keycode == XK_Up)
		player_mouv->y -= 1;
	else if(keycode == XK_Down)
		player_mouv->y += 1;
	else if (keycode == XK_Left)
		player_mouv->x -= 1;
	else if (keycode == XK_Right)
		player_mouv->x +=1;
	return (0);
}


