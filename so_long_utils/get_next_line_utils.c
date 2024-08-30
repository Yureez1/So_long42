/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/29 22:43:55 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

// TO EXTRACT A SUB STRING
char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	substrlen;

	if (s == NULL)
		return (NULL);
	substrlen = ft_strlen(s);
	if (start >= substrlen)
		return (ft_strdup(""));
	if (start + len > substrlen)
		len = substrlen - start;
	i = 0;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
// TO CHECK THE '\N'

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
// TO COPY THE STRING READ

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		copy[i] = s1[i];
	copy[len] = '\0';
	return (copy);
}

// TO CONCATENATE THE DIFFERENTS STRINGS/CHARACTER READ

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

// CHECK THE LENGTH TO MALLOC

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
