/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_atoi_base11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:12:30 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/16 10:30:15 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	rs_isvalid(char ch, int base);
int	rs_atoi_base(char *str, int base);

int	main(int argc, char **argv)
{
	char	*src;
	int		base;
	int		res;
	(void)argc;

	src = argv[1];
	base = atoi(argv[2]);
	res = rs_atoi_base(src, base);
	printf("%d\n", res);

}

int	rs_isvalid(char ch, int base)
{
	char	*lcbase = "0123456789abcdef";
	char	*ucbase = "0123456789abcdef";
	int	i;
	i = 0;
	while (i < base)
	{
		if (ch == lcbase[i] || ch == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

int rs_atoi_base(char *str, int base)
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
