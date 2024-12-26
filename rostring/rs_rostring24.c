/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_rostring24.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:04:59 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/26 16:12:20 by rhvidste         ###   ########.fr       */
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
	char	*str;
	int	first_word_start;
	int	first_word_end;
	int	i;

	i = 0;
	str = argv[1];
	if (argc == 2)
	{
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
	write(1, "\n", 1);
}
