/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_fprime10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:02:38 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/22 18:05:42 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	num;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		i = 1;
		if (num == 1)
			printf("1");
		while (num >= ++i)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num == i)
					break;
				printf("*");
				num /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}
