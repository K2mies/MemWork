/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_memset00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:30:08 by rhvidste          #+#    #+#             */
/*   Updated: 2024/10/30 09:44:40 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*rs_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

int	main()
{
	int	i;
	int	len;
	int	arr[5];
	
	i = 0;
	len = sizeof(arr) / sizeof(arr[0]);
	rs_memset(arr, 0, sizeof(arr));

	while (i < len)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}

}
