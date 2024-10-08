/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:27:46 by jbanchon          #+#    #+#             */
/*   Updated: 2024/10/08 14:51:10 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *pointer, int value, size_t count);
size_t	ft_strlen(char const *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *first, const char *second);

#endif