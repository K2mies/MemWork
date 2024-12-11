/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_itoa11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:45:17 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 13:50:13 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	rs_strlen(const char *str);
int		rs_len(int nbr);
char	*rs_itoa(int n);

int		main(int arg, char **argv)
{

}

char	*rs_itoa(int n)
{
	char	*res;
	long	nbr;
	int		len;
	int		i;

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
		res = ((nbr % 10) + '0');
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
