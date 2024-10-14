/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:00:29 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/14 16:56:32 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/so_long.h"
#include "get_next_line.h"

void	free_stash(void)
{
	get_next_line(-23);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), stash = NULL, NULL);

	stash = ft_fill_buffer(fd, stash, buf);
	free(buf);

	if (!stash || stash[0] == '\0')  // Vérifiez si stash est vide
		return (free(stash), stash = NULL, NULL);

	// Définir la ligne à partir du contenu de stash
	char *line = ft_define_line(&stash);
	return (line); // Retourner la ligne
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
		{
			free(stash);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
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

	if (line_buf == NULL)
		return (NULL);
	i = 0;
	while (line_buf[i] != '\n' && line_buf[i])
		i++;
	if (line_buf[i] == '\0')
		return (NULL);
	stash = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - (i + 1));
	if (stash == NULL)
		return (NULL);
	line_buf[i + 1] = '\0';
	return (stash);
}

/*char	*ft_define_line(char **stash)
{
	size_t	i;
	char	*line;

	if (*stash == NULL)
		return (NULL);
	
	i = 0;
	while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
		i++;
	
	// Si on a atteint la fin de stash sans trouver de '\n'
	if ((*stash)[i] == '\0')
	{
		line = ft_strdup(*stash);
		free(*stash); // Libérer stash
		*stash = NULL; // Réinitialiser stash
		return (line); // Retourner la ligne
	}

	// Créer la ligne avec '\n'
	line = ft_substr(*stash, 0, i + 1);
	char *new_stash = ft_substr(*stash, i + 1, ft_strlen(*stash) - (i + 1));
	free(*stash); // Libérer l'ancienne stash
	*stash = new_stash; // Mettre à jour stash

	return (line);
}*/


// CHECK THE LENGTH TO MALLOC

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}





int main(int argc, char **argv)
{
    int fd;
    char *line;

    // Vérifiez que le nom du fichier a été passé en argument
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Ouvrir le fichier en mode lecture
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    // Lire le fichier ligne par ligne
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Affiche la ligne lue
        free(line); // Libère la mémoire allouée pour la ligne
    }

    // Fermer le fichier
    close(fd);
    return 0;
}
