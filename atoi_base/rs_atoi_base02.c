/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_atoi_base02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:07:24 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/10 11:54:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		rs_atoi_base(const char *str, int str_base);

int		rs_isvalid(char ch, int str_base);

int		main(int argc, char **argv)
{
	char	*str;
	int		str_base;
	int		res;
	(void)argc;

	str = argv[1];
	str_base = atoi(argv[2]);
	res = rs_atoi_base(str, str_base);
	printf("results of rs_atoi_base: %d", res);
}

int		rs_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		res;
	int		i;

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
	{
		i++;
	}
	while (str[i] && rs_isvalid(str[i], str_base))
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sign);
} 

int		rs_isvalid(char ch, int str_base)
{
	char	*lcbase = "0123456789abcdef";
	char	*ucbase = "0123456789ABCDEF";
	int	i;

	i = 0;

	while (i < str_base)
	{
		if (ch == lcbase[i] || ch == ucbase[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
