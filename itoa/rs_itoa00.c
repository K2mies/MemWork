/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_itoa00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:28:33 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/11 15:32:27 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	rs_strlen(const char *str);
int		rs_abs(int nbr);
int		rs_count(int nbr);
char	*rs_itoa(int nbr);

int		main(int argc, char **argv)
{
	size_t	i;
	size_t	len;
	int		nbr;
	char	*res;
	(void)argc;

	nbr = atoi(argv[1]);
	res = rs_itoa(nbr);
	len = rs_strlen(res);
	
	i = 0;
	while(i < len + 1)
	{
		if (res[i] == '\0')
			printf("res[%zu] = \\0\n", i);
		else
			printf("res[%zu] = %c\n", i, res[i]);
		i++;
	}
}

size_t	rs_strlen(const char *str)
{
	size_t	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
int		rs_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}
int		rs_count(int nbr)
{
	int	i;
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*rs_itoa(int nbr)
{
	char	*res;
	int		len;
	int		i;

	i = 0;

	len = rs_count(nbr);
	if (nbr < 0)
		i++;
	len += i;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[0] = '-';
	res[len] = '\0';
	while ((len - 1) >= i)
	{
		res[len -1] = rs_abs(nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (res);
}
