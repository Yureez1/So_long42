/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:21:15 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/28 14:39:46 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

char *ft_strncpy(char *dest, const char *src, size_t length)
{
	size_t	i;
	
	i = 0;
	while (src[i] != '\0' && i < length)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
