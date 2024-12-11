/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:04:52 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/01 18:45:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;


	i = 0;
	while (big[i])
	{
		j = 0;
		while (i < len && big[i + j] != '\0' && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)(big + i));
			}
			++j;
		}
		++i;
	}
	
}
