/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_is_power_of_2_04.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:15:39 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/29 17:20:29 by rhvidste         ###   ########.fr       */
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
	int	src;
	int	res;

	(void)argc;

	src = atoi(argv[1]);
	res = is_power_of_2(src);
	printf("res = %d\n", res);
}
