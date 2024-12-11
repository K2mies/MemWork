/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_memmove01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:29:15 by rhvidste          #+#    #+#             */
/*   Updated: 2024/10/31 09:55:08 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*rs_memcpy(void *dest, const void *src, size_t n);
void	*rs_memmove(void *dest, const void *src, size_t n);

int	main()
{
	int	src[] = {1,2,3,4,5,6,7,8,9,10};
	int	dest[10];

	int	i;
	//int	len;

	rs_memmove(dest, src, sizeof(int) * 10);
	rs_memmove(dest+2, dest, sizeof(int) * 8);

	i = 0;
	while (i < 10)
	{
		printf("dest[%d] = %d\n", i, dest[i]);
		i++;
	}
}

void	*rs_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*dst;

	temp = (char *)src;
	dst = (char *)dest;
	if (temp < dst)
	{
		while (n--)
			dst[n] = temp[n];
	}
	else
		rs_memcpy(dst, temp, n);
	return (dst);
}

void	*rs_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
			return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
