/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_range00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:27:32 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/05 15:30:46 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*rs_range(int min, int max);

int	main(int argc, char **argv)
{

	int		*arr;
	int		min;
	int		max;
	int		len;
	int		i;

	(void)argc;

	min = atoi(argv[1]);
	max = atoi(argv[2]);
	len = max - min + 1;
	i = -1;

	arr = rs_range(min, max);

	while (++i < len)
	{
		printf("tab[%d] = %d \n", i, arr[i]);
	}
}

int	*rs_range(int min, int max)
{
	int		*res;
	int		len;
	int		i;

	if (min > max)
	{
		return (NULL);
	}
	len =  max - min + 1;
	res = malloc(sizeof(int) * len);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i++] = max--;
	}
	return (res);

}
