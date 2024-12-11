/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_inter06.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:54:27 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 11:01:26 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rs_inter(const char *s1, const char *s2);

int		main(int argc, char **argv)
{
		char	*s1;
		char	*s2;

		if (argc > 3 || argc < 3)
		{
			write(1, "\n", 1);
			return (0);
		}
		s1 = argv[1];
		s2 = argv[2];

		rs_inter(s1, s2);
		write(1, "\n", 1);
}

void	rs_inter(const char *s1, const char *s2)
{
	size_t	i;
	int		tab[256] = {0};

	i = 0;
	while (s2[i])
	{
		tab[(int)s2[i++]] = 1;
	}
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			tab[(int)s1[i]] = 2;
		}
		i++;
	}
}
