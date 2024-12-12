/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_atoi_base07.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:28:16 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/12 16:44:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	rs_atoi_base(char *str, int base);
int	rs_isvalid(char ch, int base);

int	main(int argc, char **argv)
{
	char	*str;
	int		base;
	int		res;
	(void)argc;

	str = argv[1];
	base = atoi(argv[2]);
	res = rs_atoi_base(str, base);
	printf("%d\n", res);
}

int	rs_isvalid(char ch, int base)
{
	char	*ucbase = "0123456789abcdef";
	char	*lcbase = "0123456789ABCDEF";
	int		i;

	i = 0;

	while (i < base)
	{
		if (ch == lcbase[i] || ch == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

int	rs_atoi_base(char *str, int base)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && rs_isvalid(str[i], base))
	{
		res *= base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sign);
}
