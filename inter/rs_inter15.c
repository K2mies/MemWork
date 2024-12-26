/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_inter15.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:46:45 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/25 13:52:42 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rs_inter(char *s1, char *s2)
{
	int	tab[256] = {0};
	int	i;

	i = 0;
	while (s2[i])
	{
		tab[(int)s2[i++]] = 1;
	}
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s2[i]] == 1)
		{
			write(1, &s1[i], 1);
			tab[(int)s2[i]] = 2;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;

	(void)argc;

	s1 = argv[1];
	s2 = argv[2];

	rs_inter(s1, s2);
}
