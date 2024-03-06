/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:29:02 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/10 13:22:54 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putptr(size_t ptr, int *len);
void	ft_putnbr(long n, int *len);
void	ft_putunsigned(unsigned int u, int *len);
void	ft_puthex(unsigned int x, int *len, char spec);

#endif
