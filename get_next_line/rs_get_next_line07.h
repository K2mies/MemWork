/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_get_next_line07.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:00:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/03/01 17:03:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//MACROS
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

//INCLUDES
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

//DEFINITIONS
char *ft_strdup(char *str);
char *get_next_line(int fd);

# endif
