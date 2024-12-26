/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rrange04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:52:04 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/26 13:59:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*rs_rrange(int start, int end);

int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	*res;
	int	len;
	int	i;
	(void)argc;

	start = atoi(argv[1]);
	end = atoi(argv[2]);
	if (start >= end)
		len = start - end;
	else
		len = end - start;
	res = rs_rrange(start, end);
	i = 0;
	while (i < len + 1)
	{
		printf("res[%d] = %d\n", i, res[i]);
		i++;
	}
}

int	*rs_rrange(int start, int end)
{
	int	i;
	int	len;
	int	*res;
	
	if (start >= end)
		len = start - end;
	else
		len = end - start;
	res = malloc(sizeof(int) * len);
	i = 0;
	while (i <= len)
	{
		if (start >= end)
			res[i] = end++;
		else
			res[i] = end--;
		i++;
	}
	return (res);
}
