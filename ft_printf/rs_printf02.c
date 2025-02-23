/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_printf02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:58:24 by rhvidste          #+#    #+#             */
/*   Updated: 2025/02/23 20:19:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_printpercent(int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int n, int *len);
void	ft_puthex(unsigned int n, char c, int *len);

void	ft_format(char c, int *len, va_list args);
int	ft_printf(const char *str, ...);

void	ft_printpercent(int *len)
{
	*len += write(1, "%", 1);
}

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	int	i = -1;

	if (!str)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (str[++i])
	{
		*len += write(1, &str[i], 1);
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		ft_putnbr(147483648, len);
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
		ft_putnbr(n, len);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + 48, len);
}

void	ft_puthex(unsigned int n, char c, int *len)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c, len);
		ft_puthex(n % 16, c, len);
	}
	if (n < 16)
	{
		if (c == 'x')
			ft_putchar("0123456789abcdef"[n], len);
	}
}

void	ft_format(char c, int *len, va_list args)
{
	if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	if (c == 'd')
		ft_putnbr(va_arg(args, int), len);
	if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), c, len);
	if (c == '%')
		ft_printpercent(len);
}

int	ft_printf(const char *str, ...)
{
	int	i = 0;
	int	len = 0;
	va_list args;

	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i], &len, args);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	printf("%s\n", (char *)NULL);
	ft_printf("%s\n", (char *)NULL);
	printf("%d\n", 14324);
	ft_printf("%d\n", 14324);
	printf("%%\n");
	ft_printf("%%\n");
	printf("%x\n", 14324);
	printf("%x\n", 14324);
}
