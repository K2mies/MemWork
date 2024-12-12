/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_itoa15.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:15 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/12 16:27:43 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	rs_strlen(const char *str);
int		rs_len(int nbr);
char	*rs_itoa(int n);

int	main(int argc, char **argv)
{
	char	*res;
	int		src;
	size_t	len;
	size_t	i;
	(void)argc;

	src = atoi(argv[1]);
	res = rs_itoa(src);
	len = rs_strlen(res);
	i = 0;
	while (i < len + 1)
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

int	rs_len(int nbr)
{
	int	i;
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char *rs_itoa(int n)
{
	int		i;
	int		len;
	long	nbr;
	char	*res;

	i = 0;
	len = rs_len(n);
	nbr = (long)n;
	if (nbr < 0)
		nbr = -nbr;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = len -1;
	while (nbr != 0)
	{
		res[i] = ((nbr % 10) + '0');
		nbr /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	res[len] = 0;
	return (res);
}	
