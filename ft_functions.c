/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:28:25 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/10 13:22:41 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, len);
}

void	ft_putptr(size_t ptr, int *len)
{
	char	str[17];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	if (ptr == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	i = 0;
	while (ptr)
	{
		str[i] = base[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_putnbr(long n, int *len)
{
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
		ft_putnbr(n, len);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
}

void	ft_putunsigned(unsigned int u, int *len)
{
	if (u >= 10)
		ft_putunsigned(u / 10, len);
	ft_putchar(u % 10 + '0', len);
}

void	ft_puthex(unsigned int x, int *len, char spec)
{
	char	str[17];
	int		i;
	char	*base;

	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (x == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	i = 0;
	while (x)
	{
		str[i] = base[x % 16];
		x /= 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

/* int main()
{
	int a = 0;
	ft_putstr(0, &a);
	ft_putstr("\nIgor\n", &a);
} */
