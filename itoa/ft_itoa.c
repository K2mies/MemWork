/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:51:34 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/09 12:51:05 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_len(long nbr);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

int		main(int argc, char **argv)
{
	char	*res;
	int		src;
	size_t	len;
	size_t	i;
	(void)argc;

	src = atoi(argv[1]);
	res = ft_itoa(src);
	len = ft_strlen(res);
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

size_t	ft_strlen(const char *str)
{
	size_t	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;
	long	nbr;

	len = ft_len(n);
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

static int	ft_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{	
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
