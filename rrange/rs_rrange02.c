/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rrange02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:48:12 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 15:59:35 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*rs_rrange(int start, int end)
{
	int	len;
	int	*res;
	int	i;

	len = end - start;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	i = 0;
	while (end >= start)
	{
		res[i++] = end--;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	int	*res;
	int	start;
	int	end;
	int	len;
	int	i;
	(void)argc;

	start = atoi(argv[1]);
	end = atoi(argv[2]);
	len = end - start;
	res = rs_rrange(start, end);
	i = 0;
	while (i < len + 1)
	{
		printf("res[%d] = %d\n", i, res[i]);\
		i++;
	}
}
