/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_get_next_line06.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:52:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/03/01 16:59:47 by rhvidste         ###   ########.fr       */
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

//Definitions
char *get_next_line(int fd);

# endif
