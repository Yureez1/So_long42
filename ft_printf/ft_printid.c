/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:59 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 20:00:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include "../includes/so_long.h"

size_t	ft_numlen(int value)
{
	size_t	length;

	length = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		value = -value;
		length++;
	}
	while (value != 0)
	{
		value = value / 10;
		length++;
	}
	return (length);
}

void	ft_printid(int value, int *counter)
{
	ft_putnbr_fd(value, 1);
	(*counter) += ft_numlen(value);
}
