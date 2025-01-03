/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_print_hex13.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:14:01 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/03 10:23:59 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		rs_atoi(const char *str)
{
	int	i = 0;
	int	n = 0;

	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		++i;
	}
	return (n);
}
void	rs_print_hex(int n)
{
	char	hex_digits[] = "0123456789abcdef";
	if (n >= 16)
		rs_print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rs_print_hex(rs_atoi(argv[1]));
	write(1, "\n", 1);
}
