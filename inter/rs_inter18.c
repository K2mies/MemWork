/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_inter18.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:01:43 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/29 16:09:51 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rs_inter(char *s1, char *s2)
{
	int	seen[256] = {0};
	int	i = 0;

	while (s2[i])
	{
		seen[(int)s2[i++]] = 1;
	}
	i = 0;
	while (s1[i])
	{
		if (seen[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			seen[(int)s1[i]] = 2;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];

		rs_inter(s1, s2);
	}
	write(1, "\n", 1);
	return (0);
}
