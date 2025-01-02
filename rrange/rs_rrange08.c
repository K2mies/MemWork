/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rrange08.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:29:59 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/02 15:37:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*rs_rrange(int start, int end);

int	main(int argc, char **argv)
{
	int		start;
	int		end;
	int		len;
	int		*res;
	int		i = 0;

	(void)argc;

	start = atoi(argv[1]);
	end	= atoi(argv[2]);
	
	if (start > end)
		len = start - end;
	else
		len = end - start;
	
	res = rs_rrange(start, end);
	while (i <= len)
	{
		printf("res[%d] = %d\n", i, res[i]);
		i++;
	}
	free(res);
}

int	*rs_rrange(int start, int end)
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
