/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:40 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/14 16:26:42 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/so_long.h"
#include "get_next_line.h"

// TO EXTRACT A SUB STRING

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substrlen;

	if (s == NULL)
		return (NULL);
	substrlen = ft_strlen(s);
	if (start >= substrlen)
		return (ft_strdup(""));
	if (start + len > substrlen)
		len = substrlen - start;
	return (create_substr(s, start, len));
}

char	*create_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
