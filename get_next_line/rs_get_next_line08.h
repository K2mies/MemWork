/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_get_next_line08.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:06:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/03/01 18:08:15 by rhvidste         ###   ########.fr       */
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
