/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_is_power_of_2_06.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:22:56 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/03 11:28:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return (n & (n - 1)) == 0;
}

int	main(int argc, char **argv)
{
	int		src;
	(void)argc;

	src = atoi(argv[1]);
	printf("%d\n", is_power_of_2(src));
}
