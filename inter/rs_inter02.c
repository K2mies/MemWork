/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_inter02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:16:42 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/09 16:40:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	rs_inter(char *s1, char *s2);

int		main(int argc, char **argv)
{
	(void)argc;
	char	*s1;
	char	*s2;

	s1 = argv[1];
	s2 = argv[2];

	rs_inter(s1, s2);
}

void	rs_inter(char *s1, char *s2)
{
	size_t	i;
	int	tab[256] = {0};

	i = 0;
	while (s2[i])
	{
		tab[(int)s2[i++]] = 1;
	}
	i = 0;
	while (s1[i])
	{
		if(tab[(int)s2[i]] == 1)
		{
			write (1, &s1[i], 1);
			tab[(int)s2[i]] = 2;
		}
		i++;
	}
}
