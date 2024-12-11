/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:03:28 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/05 13:45:47 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	*ft_range(int min, int max);

int main(int argc, char **argv)
{
	(void) argc;
	int len;
	int i;
	int min;
	int max;

	min = atoi(argv[1]);
	max = atoi(argv[2]);

	printf("min = %d\nmax = %d\n", min, max);

	int *arr = ft_range(min, max);

	len = max - min;

	if (arr)
	{
		printf("not NULL\n");
	}
	else
		printf("NULL");

	i = 0;
	while (i < len)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
}

int	*ft_range(int min, int max)
{
	int	*arr;
	int	len;
	int	i;

	len = max - min;
	arr = (int *)malloc(sizeof(arr) * (len));
	if (min >= max)
	{
		return (NULL);
	}
	else
	{
		i = 0;
		while (min < max)
		{
			arr[i] = min;
			min++;
			i++;
		}
		return (arr);
	}
}
