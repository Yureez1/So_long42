/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:46:30 by julien            #+#    #+#             */
/*   Updated: 2024/08/28 14:39:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

size_t	ft_strnlen(char const *str, size_t length)
{
	size_t	i;

	i = 0;
	while (str[i] && i < length)
		i++;
	return (i);
}
