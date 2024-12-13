/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_range01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:40:02 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 15:47:46 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*rs_range(int start, int end)
{
	int		i;
	int		len;
	int		*res;
	i = 0;
	len = end - start;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while(start <= end)
	{
		res[i++] = start++;
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
	res = rs_range(start, end);
	i = 0;
	while (i < len + 1)
	{
		printf("res[%d] = %d\n", i, res[i]);
		i++;
	}
}
