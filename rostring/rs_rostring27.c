/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rostring27.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:04:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/02 15:29:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	write_word(int start, int end, char *str)
{
	while (start < end)
		write(1, &str[start++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	*str;
		int		first_word_start;
		int		first_word_end;
		int		i = 0;
		str = argv[1];
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		first_word_start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		first_word_end = i;
		if (str[i])
		{
			while (str[i])
			{
				if (str[i] && (str[i] == ' ' || str[i] == '\t'))
				{
					while (str[i] && (str[i] == ' ' || str[i] == '\t'))
						i++;
					if (str[i])
						write(1, " ", 1);
				}
				else
				{
					write(1, &str[i], 1);
					i++;
				}
			}
			write(1, " ", 1);
		}
		write_word(first_word_start, first_word_end, str);
	}
	write (1, "\n", 1);
	return (0);
}
