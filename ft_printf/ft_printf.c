/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:36 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/05 17:27:28 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_type(const char c, va_list args, int *counter)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		(*counter)++;
	}
	else if (c == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (c == 'd' || c == 'i')
		ft_printid(va_arg(args, int), counter);
	else if (c == 'u')
		ft_printu(va_arg(args, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(args, unsigned int), c, counter);
	else if (c == 'p')
		ft_printp(va_arg(args, unsigned long long), counter);
	else if (c != 0)
	{
		ft_putchar(c);
		(*counter)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		i;

	va_start(args, str);
	counter = 0;
	i = 0;
	if (!str)
		return (va_end(args), -1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_type(str[i], args, &counter);
		}
		else
		{
			ft_putchar(str[i]);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
