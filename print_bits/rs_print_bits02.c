/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_print_bits02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:09:25 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/14 16:13:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	rs_print_bits(unsigned char octet);

int	main(int argc, char **argv)
{
	int	src;
	(void)argc;
	
	src = atoi(argv[1]);
	rs_print_bits(src);
}

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
