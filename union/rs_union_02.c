/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_union_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:09:51 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/28 22:13:52 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	find[256] = {0};
		int	i = 0;
		int	j = 0;

		while (argv[1][i])
		{
			if (!find[(unsigned char)argv[1][i]])
			{
				write(1, &argv[1][i], 1);
				find[(unsigned char)argv[1][i]] = 1;
			}
			i++;
		}
		while (argv[2][j])
		{
			if (!find[(unsigned char)argv[2][j]])
			{
				write(1, &argv[2][j], 1);
				find[(unsigned char)argv[2][j]] = 1;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
