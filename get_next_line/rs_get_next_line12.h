/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_get_next_line12.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:20:38 by rhvidste          #+#    #+#             */
/*   Updated: 2025/03/02 22:23:11 by rhvidste         ###   ########.fr       */
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
