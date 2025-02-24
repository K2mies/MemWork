/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_printf10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:50:09 by rhvidste          #+#    #+#             */
/*   Updated: 2025/02/24 17:08:30 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	rs_printpercent(int *len);
void	rs_putchar(char c, int *len);
void	rs_putstr(char *str, int *len);
void	rs_putnbr(int n, int *len);
void	rs_puthex(unsigned int n, char c, int *len);

void	rs_format(char c, int *len, va_list args);
int		rs_printf(const char *str, ...);

void	rs_printpercent(int *len)
{
	*len += write(1, "%", 1);
}

void	rs_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	rs_putstr(char *str, int *len)
{
	int		i = -1;

	if (!str)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*len += write(1, &str[i], 1);
	}
}

void	rs_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		rs_putchar('-', len);
		rs_putchar('2', len);
		rs_putnbr(147483648, len);
	}
	if (n < 0)
	{
		rs_putchar('-', len);
		n = -n;
		rs_putnbr(n, len);
	}
	if (n > 9)
	{
		rs_putnbr(n / 10, len);
		rs_putnbr(n % 10, len);
	}
	else
		rs_putchar(n + 48, len);
}

void	rs_puthex(unsigned int n, char c, int *len)
{
	if(n >= 16)
	{
		rs_puthex(n / 16, c, len);
		rs_puthex(n % 16, c, len);
	}
	else
	{
		if (c == 'x')
			rs_putchar("0123456789abcdef"[n], len);
	}
}

void	rs_format(char c, int *len, va_list args)
{
	if (c == 's')
		rs_putstr(va_arg(args, char *), len);
	if (c == 'd')
		rs_putnbr(va_arg(args, int), len);
	if (c == 'x')
		rs_puthex(va_arg(args, unsigned int), c, len);
	if (c == '%')
		rs_printpercent(len);
}

int		rs_printf(const char *str, ...)
{
	int		i = 0;
	int		len = 0;
	va_list	args;

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			rs_format(str[i], &len, args);
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
	rs_printf("%s\n", (char *)NULL);
	printf("%d\n", 12345);
	rs_printf("%d\n", 12345);
	printf("%%\n");
	rs_printf("%%\n");
	printf("%x\n", 12345);
	rs_printf("%x\n", 12345);
}
