/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:07:05 by rhvidste          #+#    #+#             */
/*   Updated: 2024/10/30 09:44:15 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
		size_t	i;

		if(!s)
			return (NULL);
		i = 0;
		while (i < n)
		{
			*(unsigned char*)(s + i) = (unsigned char)c;
			i++;
		}
		return (s);
}

int	main()
{
	int	i;
	int arr[5];

	i = 0;
	ft_memset(arr, 0, sizeof(arr));

	while (i < 5)
	{
			printf("arr[%d] = %d\n", i, arr[i]);
			i++;
	}
}
