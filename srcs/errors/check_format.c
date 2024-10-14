/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:16:59 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/13 23:09:07 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_ber_file(const char *filename)
{
	if (filename == NULL || ft_strlen(filename) < 4)
		return (0);
	return (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) == 0);
}

