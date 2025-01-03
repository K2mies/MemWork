/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rrange09.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:43:38 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/03 11:48:57 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*rs_rrange(int start, int end)
{
	int		len;
	int		*res;
	int		i = 0;

	if (start > end)
		len = start - end;
	else
		len = end - start;
	
	res = malloc(sizeof(int) * len);
	while (i <= len)
	{
		if (start > end)
			res[i++] = end++;
		else
			res[i++] = end--;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	int		len;
	int		*res;
	int		start;
	int		end;
	int		i = 0;

	(void)argc;

	start = atoi(argv[1]);
	end = atoi(argv[2]);
	
	if (start > end)
		len = start - end;
	else
		len = end - start;
	
	res = rs_rrange(start, end);

	while (i < len + 1)
	{
		printf("res[%d] = %d\n", i, res[i]);
		i++;
	}
}
