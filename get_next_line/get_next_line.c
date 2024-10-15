/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/15 16:57:40 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_stash(void)
{
	get_next_line(-23);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || fd < 0)
		return(NULL);
	line = ft_fill_buffer(fd, stash, buf);
	free(buf);
	if (!line)
		return (NULL);
	stash = ft_define_line(line);
	return (line);
}


// FONCTION QUI LIT LE FICHIER
char	*ft_fill_buffer(int fd, char *stash, char *buf)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return(free(stash), NULL);
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		if (!stash)
			return (NULL);
		temp = stash;
		stash = ft_strjoin(temp, buf);
		if (!stash)
			return (free(stash), NULL);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_define_line(char *line_buf)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line_buf[i] != '\n' && line_buf[i])
		i++;
	if (line_buf[i] == '\0')
		return (NULL);
	stash = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - (i + 1));
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line_buf[i + 1] = '\0';
	return (stash);
}

