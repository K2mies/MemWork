/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:46:11 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/11 15:04:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	rs_isvalid(int ch, int baselen);
int	ft_atoi_base(const char *str, int str_base);

int	main(int argc, char **argv)
{
	char	*str;
	int		str_base;
	int		res;
	(void)argc;

	str = argv[1];
	str_base = atoi(argv[2]);
	res = ft_atoi_base(str, str_base);
	printf("result of ft_atoi_base: %d", res);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;

	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
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

int	rs_isvalid(int ch, int baselen)
{
	char	*lcbase = "0123456789abcdef";
	char	*ucbase = "0123456789ABCDEF";
	int		i;

	i = 0;

	while (i < baselen)
	{
		if(ch == lcbase[i] || ch == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}
