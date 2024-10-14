/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/14 16:58:42 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/so_long.h"
#include "get_next_line.h"

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

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		strlen;

	i = 0;
	strlen = ft_strlen(src);
	dest = malloc(sizeof(char) * (strlen + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// TO CONCATENATE THE DIFFERENTS STRINGS/CHARACTER READ

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*len_final;
	size_t	index;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	len_final = malloc(size + 1);
	if (len_final == NULL)
		return (NULL);
	index = 0;
	ft_str_copy(len_final, s1, &index);
	ft_str_copy(len_final + index, s2, &index);
	len_final[size] = '\0';
	return (len_final);
}

void	ft_str_copy(char *dest, const char *src, size_t *index)
{
	while (src[*index] != '\0')
	{
		dest[*index] = src[*index];
		(*index)++;
	}
}
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
