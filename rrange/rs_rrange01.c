/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rrange01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:40:51 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 12:50:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*rs_rrange(int min, int max);

int		main(int argc, char **argv)
{
	int		min;
	int		max;
	int 	*res;
	int		len;
	int		i;
	(void)argc;

	min = atoi(argv[1]);
	max = atoi(argv[2]);
	len = max - min;

	res = rs_rrange(min, max);
	i = 0;
	while (i < len + 1)
	{
		printf("res[%d] = %d\n", i, res[i]);
		i++;
	}

}

int		*rs_rrange(int min, int max)
{
	int	*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = max - min;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (max >= min)
	{
		res[i++] = max--;
	}
	return (res);
}
