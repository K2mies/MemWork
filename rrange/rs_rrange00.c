/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rrange00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:01:19 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 12:49:55 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*rs_rrange(int min, int max);

int	main(int argc, char **argv)
{
	int		min;
	int		max;
	int		*res;
	size_t	len;
	size_t	i;
	(void)argc;

	min = atoi(argv[1]);
	max = atoi(argv[2]);
	len = max - min + 1;
	i = -1;

	res = rs_rrange(min, max);

	while (++i < len)
	{
		printf("res[%zu] = %d\n", i, res[i]);
	}
}

int	*rs_rrange(int min, int max)
{
	int		*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = max - min + 1;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = max--;
	}
	return (res);
}
