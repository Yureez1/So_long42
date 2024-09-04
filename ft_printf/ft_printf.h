/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:16 by jbanchon          #+#    #+#             */
/*   Updated: 2024/09/04 20:01:13 by jbanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_putstr(char *value, int *counter);
void	ft_printid(int value, int *counter);
void	ft_printu(unsigned int value, int *counter);
void	ft_printhex(unsigned int value, const char c, int *counter);
void	ft_putptr(uintptr_t value);
void	ft_type(const char c, va_list args, int *counter);
int		ft_printf(const char *str, ...);
size_t	ft_hexlen(unsigned int value);
size_t	ft_numlen(int value);
size_t	ft_ptrlen(uintptr_t value);
void	ft_printp(unsigned long long value, int *counter);
void	ft_putchar(char c);

#endif
