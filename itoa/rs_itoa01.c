/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_itoa01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:03:36 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 10:12:51 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	rs_strlen(const char *str);
int		rs_len(int nbr);
char	*rs_itoa(int n);

int		main(int argc, char **argv)
{	
	size_t	i;
	size_t	len;
	int		src;
	char	*res;
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
	size_t		i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*rs_itoa(int n)
{
	int		i;
	int		len;
	char	*res;
	long	nbr;

	len = rs_len(n);
	res = malloc(sizeof(char) * len + 1);
	nbr = (long)n;
	if (!res)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		res[i] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	res[len] = 0;
	return (res);

}

int		rs_len(int nbr)
{
	size_t		count;
	count = 0;

	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		count++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
