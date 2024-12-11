/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:11:12 by rhvidste          #+#    #+#             */
/*   Updated: 2024/10/31 09:54:40 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp;
	char	*dest;

	temp = (char *)src;
	dest = (char *)dst;
	if (temp < dest)
	{
		while (n--)
			dest[n] = temp[n];
	}
	else
		ft_memcpy(dest, temp, n);
	return (dst);
}

int	main()
{
	int	src[10] = {1,2,3,4,5,6,7,8,9,10};
	int	dest[10];

	int	i;

	ft_memmove (dest, src, sizeof(int) * 10);
	ft_memmove (dest+2, dest, sizeof(int) * 8);
	i = 0;
	while (i < 10)
	{
		printf("src[%d] = %d\n", i, src[i]);
		i++;
	}

	i = 0;
	while (i < 10)
	{
		printf("dest[%d] = %d\n", i, dest[i]);
		i++;
	}
}
