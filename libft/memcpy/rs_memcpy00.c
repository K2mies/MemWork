/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_memcpy00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:31:53 by rhvidste          #+#    #+#             */
/*   Updated: 2024/10/30 10:45:04 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

int	rs_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*src;
	char	*dest;
	int		len;
	int		i;
	(void)argc;

	src = argv[1];
	len = rs_strlen(src) + 1;
	dest = malloc(sizeof(char) * len);
	ft_memcpy(dest, src, len);
	i = 0;
	while (i < len)
	{
		if (dest[i] == '\0')
			printf("dest[%d] = \\0\n", i);
		else
			printf("dest[%d] = %c\n", i, dest[i]);
		i++;
	}
}
