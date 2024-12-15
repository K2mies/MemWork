/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_swap_bits05.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:23:28 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/15 21:28:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned char	rs_swap_bits(unsigned char octet);
void	rs_print_bits(unsigned char octet);

int	main(int argc, char **argv)
{
	int	src;
	int	res;
	(void)argc;

	src = atoi(argv[1]);
	rs_print_bits(src);
	write(1, "\n", 1);
	res = rs_swap_bits(src);
	rs_print_bits(res);
	write(1, "\n", 1);
}

unsigned char	rs_swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

void	rs_print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}

