/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life00.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:16:35 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/27 13:53:17 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE
#define LIFE

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

typedef struct	s_game
{
	int	width;
	int	height;
	int	iterations;
	char	alive;
	char	dead;
	int	i;
	int	j;
	int	draw;
	char	**board;
}		t_game;

int	init_game	( t_game *game, char **argv);
void	fill_board	( t_game *game );
int	count_neighbors	( t_game *game, int i, int j );
int	play		( t_game *game );
void	print_board	( t_game *game );
void	free_board	( t_game *game );

#endif 
