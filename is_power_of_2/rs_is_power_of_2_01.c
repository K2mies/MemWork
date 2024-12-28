/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_is_power_of_2_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:01:40 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/28 18:05:56 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	rs_is_power_of_2(unsigned int n)
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
	res = rs_is_power_of_2(src);
	printf("%d\n", res);
}
