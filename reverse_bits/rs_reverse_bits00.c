/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_reverse_bits00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:26:50 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 11:44:33 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rs_print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}	

unsigned char	rs_reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	(void)argc;
	int	src;
	int	res;

	src = atoi(argv[1]);
	rs_print_bits(src);
	write(1, "\n", 1);
	res = rs_reverse_bits(src);
	rs_print_bits(res);
	write(1, "\n", 1);
}
