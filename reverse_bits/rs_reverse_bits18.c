/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_reverse_bits18.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:54:02 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/16 15:00:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned char	rs_reverse_bits(unsigned char octet);
void	rs_print_bits(unsigned char octet);

int		main(int argc, char **argv)
{
		int		src;
		int		res;
		(void)argc;

		src = atoi(argv[1]);
		rs_print_bits(src);
		write(1, "\n", 1);
		res = rs_reverse_bits(src);
		rs_print_bits(res);
		write(1, "\n", 1);
}

unsigned char	rs_reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res;
	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

void	rs_print_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}	
