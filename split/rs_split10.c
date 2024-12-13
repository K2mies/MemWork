/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_split10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:31:42 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 13:50:26 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*rs_strncpy(char *s1, char *s2, int n);
char	**rs_split(char *str);

int		main(int argc, char **argv)
{
	char	*str;
	char	**res;
	int		i;
	(void)argc;

	str = argv[1];
	res = rs_split(str);
	i = 0;
	while (res[i])
		printf("%s\n", res[i++]);
}

char	*rs_strncpy(char *s1, char *s2, int n)
{
	int		i;
	i = -1;
	while (i++ < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**rs_split(char *str)
{
	int	i;
	int	j;
	int	k;
	int	wc;

	i = 0;
	j = 0;
	k = 0;
	wc = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	char	**out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{	
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = malloc(sizeof(char) * (i - j) + 1);
			rs_strncpy(out[k++], &str[j], (i - j));
		}
	}
	out[k] = NULL;
	return (out);
}
