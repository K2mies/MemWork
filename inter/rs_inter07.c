/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_inter07.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:23:45 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 13:30:51 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	rs_inter(const char *s1, const char *s2);

int		main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	(void)argc;

	s1 = argv[1];
	s2 = argv[2];

	rs_inter(s1, s2);
	
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
			write(1, &s1[i] , 1);
			tab[(int)s1[i]] = 2;
		}
		i++;
	}
}
