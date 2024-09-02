/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/02 19:58:47 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"

t_node	*create_new_node(char *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = ft_strdup(content);
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_node **list, char *content)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_new_node(content);
	if (!new_node)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void	free_node(t_node *node)
{
	if (node)
	{
		if (node->content)
			free(node->content);
		free(node);
	}
}
void	free_list(t_node *list)
{
	t_node	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free_node(temp);
	}
}

char	*get_next_line(int fd)
{
	static t_node	*stash;
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			bytes_read;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		if (stash)
			return (extract_line(&stash));
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	save_remaining(&stash, buffer);
	return (extract_line(&stash));
}

int	main(void)
{
	int		fd;
	char	*line;

	// Ouvrir le fichier
	fd = open("../maps/map1.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	// Lire les lignes du fichier
	while ((line = get_next_line(fd)) != NULL)
	{
		// Traitement de la ligne
		printf("%s", line);
		free(line); // Ne pas oublier de libérer la mémoire
	}
	// Fermer le fichier
	close(fd);
	return (0);
}
