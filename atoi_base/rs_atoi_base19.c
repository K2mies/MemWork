/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_atoi_base19.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:11:57 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/29 15:09:20 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	rs_isvalid(char ch, int base);
int	rs_atoi_base(char *str, int base);

int	main(int argc, char **argv)
{
	char	*src;
	int	base;
	int	res;

	(void)argc;

	src = argv[1];
	base = atoi(argv[2]);

	res = rs_atoi_base(src, base);
	printf("res = %d\n", res);
}

int	rs_isvalid(char ch, int base)
{
	char	*lcbase = "0123456789abcdef";
	char	*ucbase = "0123456789ABCDEF";
	int	i = 0;

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
	int	sign = 1;
	int	res = 0;
	int	i = 0;
	int	c = 0;

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
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'f')
			c = str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'F')
			c = str[i] - 'A' + 10;
		res = res * base + c; 
		i++;
	}
	return (res * sign);
}
