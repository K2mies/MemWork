/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_cameltosnake00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:17:44 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 11:02:07 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rs_camel_to_snake(const char *str);

int		main(int argc, char **argv)
{
	char	*str;
	char	*res;
	(void)argc;

	str = argv[1];

	rs_camel_to_snake(str);
}

void	rs_camel_to_snake(const char *str)
{
	size_t	i;
	char	c;

	c = '0';

	i = 0;
	while(str[i])
	{
		if (str[i] >= 65 && str[i] <=90)
		{
			write(1, "_", 1);
			c = str[i] + 32;
			write(1, &c, 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
