/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_bzero00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:24:49 by rhvidste          #+#    #+#             */
/*   Updated: 2024/10/30 09:36:37 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rs_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

int	main()
{
	int	i;
	int	len;
	int	arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	i = 0;
	len = sizeof(arr) / sizeof(arr[0]);
	rs_bzero(arr, sizeof(arr));
	while (i < len)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}

}
