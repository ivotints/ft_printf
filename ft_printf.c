/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:32:32 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/10 13:22:52 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void	ft_specifier(char s, va_list *args, int *len, int *i)
{
	if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_putptr(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_putunsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_puthex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_puthex(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_specifier(format[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar((char)format[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

/* #include "ft_functions.c"

int	main(void)
{
int c = -3249;
unsigned int b = -34324913;
int a = 42;
char* g;
g = NULL;

	ft_printf("my char: 			%c, %c\n", 'A', 'b');
		printf("char: 				%c, %c\n\n", 'A', 'b');

	ft_printf("my number: 			%d, %d\n", 12345, -2147483648);
		printf("number:				%d, %ld\n\n", 12345, -2147483648);

	ft_printf("my string: 			%s\n", "Igor wants a cake");
		printf("string: 			%s\n\n", "Igor wants a cake");

	ft_printf("my %%				%%\n");
		printf("%%				%%\n\n");

	ft_printf("my pointer: 			%p\n", &a);
		printf("pointer: 			%p\n\n", &a);

	ft_printf("my void pointer: 		%p\n", NULL);
		printf("void pointer: 			%p\n\n", NULL);

	ft_printf("my unsigned:			%u\n", b);
		printf("unsigned: 			%u\n\n", b);

	ft_printf("my hex: 			%X\n", c);
		printf("hex: 				%X\n\n", c);

	ft_printf("my hex: 			%x\n", c);
		printf("hex: 				%x\n\n", c);

	ft_printf("%d\n", ft_printf("My number of printed chars:	"));
		printf("%d\n", 	printf("PF number of printed chars:	"));
} */
