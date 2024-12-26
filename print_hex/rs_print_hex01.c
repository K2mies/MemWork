/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_print_hex01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:11:33 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/26 15:36:09 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	rs_atoi(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		n = n * 10 + str[i] - '0';
		++i;
	}
	return (n);
}

void	rs_print_hex(int n)
{
	char	hex_digit[] = "0123456789abcdef";
	if (n >= 16)
		rs_print_hex(n / 16);
	write (1, &hex_digit[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rs_print_hex(rs_atoi(argv[1]));
	write (1, "\n", 1);
}
