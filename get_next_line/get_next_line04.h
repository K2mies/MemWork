/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line04.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:34:59 by rhvidste          #+#    #+#             */
/*   Updated: 2025/02/28 16:36:20 by rhvidste         ###   ########.fr       */
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
char *get_next_line(int fd);
# endif
