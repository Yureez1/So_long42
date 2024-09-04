/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:56 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 20:00:00 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include "../includes/so_long.h"

size_t	ft_hexlen(unsigned int value)
{
	size_t	length;

	length = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / 16;
		length++;
	}
	return (length);
}

void	ft_puthex(unsigned int value, const char c)
{
	if (value >= 16)
	{
		ft_puthex(value / 16, c);
		ft_puthex(value % 16, c);
	}
	else
	{
		if (value <= 9)
			ft_putchar_fd((value + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((value - 10 + 'a'), 1);
			else if (c == 'X')
				ft_putchar_fd((value - 10 + 'A'), 1);
		}
	}
}

void	ft_printhex(unsigned int value, const char c, int *counter)
{
	if (value == 0)
		(*counter) += (write(1, "0", 1));
	else
	{
		ft_puthex(value, c);
		(*counter) += ft_hexlen(value);
	}
}
