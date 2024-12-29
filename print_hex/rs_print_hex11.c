/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_print_hex11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:10:46 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/29 20:16:20 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	rs_atoi(char *str);
void	rs_print_hex(int n);

int	main(int argc, char **argv)
{
	if (argc == 2)
		rs_print_hex(rs_atoi(argv[1]));
	write(1, "\n", 1);
}

int	rs_atoi(char *str)
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
