/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_is_power_of_2_03.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:34:00 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/29 13:37:32 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(int n)
{
	if (n == 0)
		return (0);
	return (n & (n - 1)) == 0;
}

int	main(int argc, char **argv)
{
	int	src = 0;
	int	res = 0;

	(void)argc;

	src = atoi(argv[1]);
	res = is_power_of_2(src);
	printf("res = %d\n", res);
}
