/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_get_next_line01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:21:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/02/27 17:05:32 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line01.h"

char	*ft_dupstr(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while(str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_read;
	static int	buffer_pos;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}
