/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:26 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/02 19:47:40 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*extract_line(t_node **stash)
{
	char	*line;
	char	*new_stash;
	size_t	i;

	if (!*stash || !(*stash)->content)
		return (NULL);
	i = 0;
	while ((*stash)->content[i] && (*stash)->content[i] != '\n')
		i++;
	if ((*stash)->content[i] == '\n')
		i++;
	line = ft_substr((*stash)->content, 0, i);
	new_stash = ft_strdup((*stash)->content + i);
	free((*stash)->content);
	free(*stash);
	*stash = create_new_node(new_stash);
	free(new_stash);
	return (line);
}

void	save_remaining(t_node **stash, char *buffer)
{
	t_node	*new_node;
	char	*combined_content;

	if (!buffer || !*buffer)
		return ;
	if (*stash == NULL)
	{
		*stash = create_new_node(buffer);
		return ;
	}
	combined_content = ft_strjoin((*stash)->content, buffer);
	free((*stash)->content);
	new_node = create_new_node(combined_content);
	free(combined_content);
	free_node(*stash);
	*stash = new_node;
}
