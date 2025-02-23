/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_itoa30.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:33:37 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/03 22:16:13 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	rs_strlen(char *str);
int	rs_len(int nbr);
char	*rs_itoa(int n);

int	main(int argc, char **argv)
{
	int	src;
	char	*res;
	int	len;
	int	i = 0;

	(void)argc;

	src = atoi(argv[1]);
	res = rs_itoa(src);
	len = rs_strlen(res);
	while (i < len + 1)
	{
		if (res[i] == '\0')
			printf("res[%d] = \\0\n", i);
		else
			printf("res[%d] = %c\n", i, res[i]);
		i++;
	}
}

int	rs_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	rs_len(int nbr)
{
	int		i = 0;

	if (nbr == -2147483648)
		return (11);;
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

char	*rs_itoa(int n)
{
		char	*res;
		long	nbr;
		int		len;
		int		i;

		len = rs_len(n);
		res = malloc(sizeof(int) * len);
		if (!res)
			return (NULL);
		i = len - 1;
		nbr = (long)n;
		if (nbr < 0)
			nbr = -nbr;
		while (nbr != 0)
		{
			res[i] = ((nbr % 10) + '0');
			nbr /= 10;
			i--;
		}
		if (n < 0)
			res[0] = '-';
		if (n == 0)
			res[0] = '+';
		res[len] = '\0';
		return (res);

}
