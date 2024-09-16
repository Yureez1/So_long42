/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/16 17:55:46 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_next_mouv(t_data *data, int keysym, char tile)
{
	if ((keysym == 'd') && data->map.grid[data->player_x
		+ 1][data->player_y] == tile)
		|| (keysym == 'a' && data->map.grid[data->player_x
			- 1][data->player_y] == tile) || (keysym == 's'
			&& data->map.grid[data->player_x][data->player_y + 1] == tile)
			|| (keysym == 'w' && data->map.grid[data->player_x][data->player_y
			- 1] == tile) return (SUCCESS);
	else
		return (EXIT);
}

void	collected_coins(t_data *data, int keysym)
{
	if ((keysym == 'd') && data->map.grid[data->player_x
		+ 1][data->player_y] == 'C')
		|| ((keysym == 'd') && data->map.grid[data->player_x
				+ 1][data->player_y]) == 'C' || ((keysym == 'd')
				&& data->map.grid[data->player_x + 1][data->player_y] == 'C')
			|| ((keysym == 'd') && data->map.grid[data->player_x
				+ 1][data->player_y] == 'C') data->map.collected++;
}

int	game_win(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (SUCCESS);
	}
	else
		return (EXIT);
}

void	player_mouv(t_data *data, int keysym)
{
	if (check_next_mouv(data, keysym, '1') == SUCCESS
		|| (data->map.can_exit == 0 && check_next_mouv(data, keysym,
				'E') == SUCCESS))
		return;
	data->count_step++;
	collected_coins(data, keysym);
	if(data->map.collected == data->map.collectible_count)
		data->map.can_exit = 1;
	data->map.grid[data->player_x][data->player_y] = '0';
	if (keysym == 'd')
		data->player_x++;
	else if (keysym == 'a')
		data->player_x--;
	else if (keysym == 's')
		data->player_y++;
	else if (keysym == 'w')
		data->player_y--;
	if (data->map.can_exit == 1 && data->map.grid[data->player_x][data->player_y] == 'E')
		game_win(data);
	data->map.grid[data->player_x][data->player_y] = 'P';
}
