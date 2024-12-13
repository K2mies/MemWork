/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_swap_bits00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:12:20 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 11:32:03 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(int argc, char **argv)
{
	(void)argc;
	int	src;
	int res;

	src = atoi(argv[1]);
	print_bits(src);
	write(1, "\n", 1);
	res = swap_bits(src);
	print_bits(res);
	write(1, "\n", 1);
	
}
