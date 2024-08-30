/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/08/29 22:45:22 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include <stdio.h> // Pour perror
#include <stdlib.h>
#include <unistd.h>

void	free_stash(void)
{
	get_next_line(-23);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*buf;
	char		*temp;
	size_t		i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (stash == NULL || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_substr(stash, 0, (stash[i] == '\n') ? i + 1 : i);
	temp = stash;
	stash = ft_substr(stash, (stash[i] == '\n') ? i + 1 : i, ft_strlen(stash)
			- ((stash[i] == '\n') ? i + 1 : i));
	free(temp);
	return (line);
}
