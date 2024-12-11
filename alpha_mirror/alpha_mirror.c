/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:51:09 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/05 17:27:07 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rs_alpha_mirror(char *str);

int	main(int argc, char **argv)
{
	char	*str;
	(void)argc;

	str = argv[1];

	rs_alpha_mirror(str);
}

void	rs_alpha_mirror(char *str)
{
	//value of 'a' = 97 and 'z' is 122, the diff is 25.
	size_t 	i;
	char	c;

	c = '0';

	i = 0;
	while (str[i])
	{
		//so say the first letter is 'b' that is 98 and should be 121 (dif 23
		//-97 to get the numerical difference and then minus that from 122;
		c =  122 - (str[i] -97);
		write(1, &c, 1);
		i++;
	}
}
