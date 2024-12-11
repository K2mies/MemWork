/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:31:30 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/09 17:00:22 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main(int argc, char **argv)
{
	(void) argc;
	int len;
	int i;
	int min;
	int max;
	int *tab;
	int size;

	min = atoi(argv[1]);
	max = atoi(argv[2]);

	printf("min = %d\nmax = %d\n", min, max);

	size = ft_ultimate_range(&tab, min, max);

	printf("size is %d\n", size);

	len = max - min;

	if (tab)
	{
		printf("not NULL\n");
	}
	else
		printf("NULL");

	i = 0;
	while (i < size)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	*result;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	result = malloc(sizeof(int) * (len));
	if (result == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = result;
	i = 0;
	while (max > min)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (i);
}
